#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <fstream>
#include <vector>
#include <unistd.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define helicopter 1
#define towerview 2
#define topview 3
#define followup 4
#define xplus 1
#define yplus 2
#define xminus 3
#define yminus 4
#define sleeping_x 1
#define sleeping_y 2
#define standing 3

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define MP make_pair
#define F first
#define S second

using namespace std;

float x1,y,z;
typedef struct heli
{
	float ang;
	float dis;
}heli;
heli helic;
int view_state ;
int game_level;
int player_state;
int player_sleep = standing;
struct VAO {
    GLuint VertexArrayID;
    GLuint VertexBuffer;
    GLuint ColorBuffer;
    GLenum PrimitiveMode;
    GLenum FillMode;
    int NumVertices;
};
typedef struct VAO VAO;
typedef struct player_s
{
  int boardx,boardy,boardx1,boardy1;
  vector<VAO> v;
}player_s;
typedef struct board
{
  float x,y,z;
  vector<float>  dim ;
  VAO v;
}board;
VAO water;
player_s player;
board game_board[45][45];
bool keys[500];
#include "level.h"
#include "construct3D.h"
#include "cube.h"
#include "board.h"
#include "player.h"

/* Function to load Shaders - Use it as it is */
	GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path) {

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if(VertexShaderStream.is_open())
	{
		std::string Line = "";
		while(getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if(FragmentShaderStream.is_open()){
		std::string Line = "";
		while(getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> VertexShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);

	// Link the program
	fprintf(stdout, "Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	std::vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) );
	glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
	fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);

	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void quit(GLFWwindow *window)
{
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}



/* Executed when a regular key is pressed/released/held-down */
/* Prefered for Keyboard events */
void keyboard (GLFWwindow* window, int key, int scancode, int action, int mods)
{
     // Function is called first on GLFW_PRESS.

    if (action == GLFW_RELEASE) {
        switch (key) {
					case GLFW_KEY_R:
						keys[GLFW_KEY_R]=0;
								break;
					case GLFW_KEY_Q:
						keys[GLFW_KEY_Q]=0;
								break;
					case GLFW_KEY_H :
						keys[GLFW_KEY_H]=0;
								break;
            case GLFW_KEY_X:
							keys[GLFW_KEY_X]=0;
									break;
						case GLFW_KEY_F:
							keys[GLFW_KEY_F]=0;
									break;
						case GLFW_KEY_A:
							keys[GLFW_KEY_A]=0;
									break;
						case GLFW_KEY_B:
							keys[GLFW_KEY_B]=0;
									break;
						case GLFW_KEY_C:
							keys[GLFW_KEY_C]=0;
									break;
            case GLFW_KEY_Y:
                keys[GLFW_KEY_Y]=0;
                break;
            case GLFW_KEY_Z:
                keys[GLFW_KEY_Z]=0;
								if(keys[GLFW_KEY_LEFT_SHIFT]) helic.dis+=0.1;
								else  helic.dis-=0.1;
                break;
						case GLFW_KEY_UP:
								move_player_up();
								if(keys[GLFW_KEY_Q]==1) quit(window);
								break;
						case GLFW_KEY_DOWN:
								move_player_down();
								if(keys[GLFW_KEY_Q]==1) quit(window);
                break;
						case GLFW_KEY_LEFT:
								move_player_left();
								if(keys[GLFW_KEY_Q]==1) quit(window);
								break;
						case GLFW_KEY_RIGHT:
								move_player_right();
								if(keys[GLFW_KEY_Q]==1) quit(window);
                break;
						case GLFW_KEY_LEFT_SHIFT:
							keys[GLFW_KEY_LEFT_SHIFT]=0;
							break;

            default:
                break;
        }
    }
    else if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_ESCAPE:
                quit(window);
              break;
							case GLFW_KEY_R:
								keys[GLFW_KEY_R]=1;
								break;
						case GLFW_KEY_Q:
							keys[GLFW_KEY_Q]=1;
							break;
							case GLFW_KEY_H :
								keys[GLFW_KEY_H]=1;
								if(GLFW_KEY_LEFT_SHIFT) view_state = helicopter;
								break;
							case GLFW_KEY_F:
								keys[GLFW_KEY_F]=1;
								if(GLFW_KEY_LEFT_SHIFT) view_state = followup;
										break;
            case GLFW_KEY_X:
              keys[GLFW_KEY_X]=1;
              break;
						case GLFW_KEY_T:
							keys[GLFW_KEY_T]=1;
							if(GLFW_KEY_LEFT_SHIFT) view_state = towerview;
							break;
						case GLFW_KEY_O:
							keys[GLFW_KEY_O]=1;
							if(GLFW_KEY_LEFT_SHIFT) view_state = topview;
							break;
            case GLFW_KEY_Y:
              keys[GLFW_KEY_Y]=1;
              break;
            case GLFW_KEY_Z:
              keys[GLFW_KEY_Z]=1;
              break;
						case GLFW_KEY_A:
							keys[GLFW_KEY_A]=1;
									break;
						case GLFW_KEY_B:
							keys[GLFW_KEY_B]=1;
									break;
						case GLFW_KEY_C:
							keys[GLFW_KEY_C]=1;
									break;
							case GLFW_KEY_LEFT_SHIFT:
								keys[GLFW_KEY_LEFT_SHIFT]=1;
								break;
            default:
                break;
        }
    }
}

/* Executed for character input (like in text boxes) */
void keyboardChar (GLFWwindow* window, unsigned int key)
{
	switch (key) {
		case GLFW_KEY_Q:
            quit(window);
            break;
		default:
			break;
	}
}

/* Executed when a mouse button is pressed/released */
void mouseButton (GLFWwindow* window, int button, int action, int mods)
{
    switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:

            break;
        case GLFW_MOUSE_BUTTON_RIGHT:

            break;
        default:
            break;
    }
}


/* Executed when window is resized to 'width' and 'height' */
/* Modify the bounds of the screen here in glm::ortho or Field of View in glm::Perspective */
void reshapeWindow (GLFWwindow* window, int width, int height)
{
    int fbwidth=width, fbheight=height;
    /* With Retina display on Mac OS X, GLFW's FramebufferSize
     is different from WindowSize */
    glfwGetFramebufferSize(window, &fbwidth, &fbheight);

	GLfloat fov = 90.0f;

	// sets the viewport of openGL renderer
	glViewport (0, 0, (GLsizei) fbwidth, (GLsizei) fbheight);

	// set the projection matrix as perspective
	/* glMatrixMode (GL_PROJECTION);
	   glLoadIdentity ();
	   gluPerspective (fov, (GLfloat) fbwidth / (GLfloat) fbheight, 0.1, 500.0); */
	// Store the projection matrix in a variable for future use
    // Perspective projection for 3D views
    // Matrices.projection = glm::perspective (fov, (GLfloat) fbwidth / (GLfloat) fbheight, 0.1f, 500.0f);

    // Ortho projection for 2D views
		Matrices.projection = glm::ortho(-30.0f,30.0f,-30.0f,30.0f, 0.1f, 500.0f);
}


// Creates the triangle object used in this sample code
void draw ()
{
  // clear the color and depth in the frame buffer
	if(keys[GLFW_KEY_R]) helic.ang++;
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // printf("%f %f %f\n",x,y,z );
  // use the loaded shader program
  // Don't change unless you know what you are doing
  glUseProgram (programID);

  // Eye - Location of camera. Don't change unless you are sure!!
  glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f), 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
  // Target - Where is the camera looking at.  Don't change unless you are sure!!
  glm::vec3 target (0, -1, 0);
  // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
  glm::vec3 up (0, 1, 0);

  // Compute Camera matrix (view)
  // Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
  //  Don't change unless you are sure!!
	Matrices.view = glm::lookAt(glm::vec3(0,0,3), glm::vec3(0,0,0), glm::vec3(1,0,0)); // Fixed camera for 2D (ortho) in XY plane

  // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
  //  Don't change unless you are sure!!
  glm::mat4 VP = Matrices.projection * Matrices.view;

  // Send our transformation to the currently bound shader, in the "MVP" uniform
  // For each model you render, since the MVP will be different (at least the M part)
  //  Don't change unless you are sure!!
  glm::mat4 MVP;	// MVP = Projection * View * Model
	display_board();
	display_player();
	construct(water);
  // Load identity to model matrix
  // draw3DObject draws the VAO given to it using current MVP matrix
}

/* Initialise glfw window, I/O callbacks and the renderer to use */
/* Nothing to Edit here */
GLFWwindow* initGLFW (int width, int height)
{
    GLFWwindow* window; // window desciptor/handle

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, "Sample OpenGL 3.3 Application", NULL, NULL);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval( 1 );

    /* --- register callbacks with GLFW --- */

    /* Register function to handle window resizes */
    /* With Retina display on Mac OS X GLFW's FramebufferSize
     is different from WindowSize */
    glfwSetFramebufferSizeCallback(window, reshapeWindow);
    glfwSetWindowSizeCallback(window, reshapeWindow);

    /* Register function to handle window close */
    glfwSetWindowCloseCallback(window, quit);

    /* Register function to handle keyboard input */
    glfwSetKeyCallback(window, keyboard);      // general keyboard input
    glfwSetCharCallback(window, keyboardChar);  // simpler specific character handling

    /* Register function to handle mouse click */
    glfwSetMouseButtonCallback(window, mouseButton);  // mouse button clicks

    return window;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL (GLFWwindow* window, int width, int height)
{
    /* Objects should be created before any other gl function and shaders */
	// Create the models
	// Create and compile our GLSL program from the shaders
	game_level = 5;
	set_levels();
	set_board();
	init_player();
	view_state = helicopter;
	player_state = xplus;
	helic.ang = 340;
	helic.dis = 1;
	x1=-1;y=-1;z=1;
	programID = LoadShaders( "Sample_GL.vert", "Sample_GL.frag" );
	// Get a handle for our "MVP" uniform
	Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


	reshapeWindow (window, width, height);

    // Background color of the scene
	glClearColor (0.3f, 0.3f, 0.3f, 0.0f); // R, G, B, A
	glClearDepth (1.0f);

	glEnable (GL_DEPTH_TEST);
	glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

int main (int argc, char** argv)
{
	int width = 700;
	int height = 700;

    GLFWwindow* window = initGLFW(width, height);

	initGL (window, width, height);

    double last_update_time = glfwGetTime(), current_time;

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {

        // OpenGL Draw commands
        draw();
				if(keys[GLFW_KEY_Q]){  quit(window); }
        // Swap Frame Buffer in double buffering
        glfwSwapBuffers(window);

        // Poll for Keyboard and mouse events
        glfwPollEvents();

        // Control based on time (Time based transformation like 5 degrees rotation every 0.5s)
        current_time = glfwGetTime(); // Time in seconds
        if ((current_time - last_update_time) >= 0.5) { // atleast 0.5s elapsed since last frame
            // do something every 0.5 seconds ..
            last_update_time = current_time;
        }
    }

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

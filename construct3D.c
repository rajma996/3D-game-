#include "construct3D.h"


struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data, GLenum fill_mode)
{
    struct VAO* vao = new struct VAO;
    vao->PrimitiveMode = primitive_mode;
    vao->NumVertices = numVertices;
    vao->FillMode = fill_mode;

    // Create Vertex Array Object
    // Should be done after CreateWindow and before any other GL calls
    glGenVertexArrays(1, &(vao->VertexArrayID)); // VAO
    glGenBuffers (1, &(vao->VertexBuffer)); // VBO - vertices
    glGenBuffers (1, &(vao->ColorBuffer));  // VBO - colors

    glBindVertexArray (vao->VertexArrayID); // Bind the VAO
    glBindBuffer (GL_ARRAY_BUFFER, vao->VertexBuffer); // Bind the VBO vertices
    glBufferData (GL_ARRAY_BUFFER, 3*numVertices*sizeof(GLfloat), vertex_buffer_data, GL_STATIC_DRAW); // Copy the vertices into VBO
    glVertexAttribPointer(
                          0,                  // attribute 0. Vertices
                          3,                  // size (x,y,z)
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );

    glBindBuffer (GL_ARRAY_BUFFER, vao->ColorBuffer); // Bind the VBO colors
    glBufferData (GL_ARRAY_BUFFER, 3*numVertices*sizeof(GLfloat), color_buffer_data, GL_STATIC_DRAW);  // Copy the vertex colors
    glVertexAttribPointer(
                          1,                  // attribute 1. Color
                          3,                  // size (r,g,b)
                          GL_FLOAT,           // type
                          GL_FALSE,           // normalized?
                          0,                  // stride
                          (void*)0            // array buffer offset
                          );

    return vao;
}

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue, GLenum fill_mode=GL_FILL)
{
    GLfloat* color_buffer_data = new GLfloat [3*numVertices];
    for (int i=0; i<numVertices; i++) {
        color_buffer_data [3*i] = red;
        color_buffer_data [3*i + 1] = green;
        color_buffer_data [3*i + 2] = blue;
    }

    return create3DObject(primitive_mode, numVertices, vertex_buffer_data, color_buffer_data, GL_FILL);
}

void draw3DObject (struct VAO* vao)
{
    // Change the Fill Mode for this object
    glPolygonMode (GL_FRONT_AND_BACK, vao->FillMode);

    // Bind the VAO to use
    glBindVertexArray (vao->VertexArrayID);

    // Enable Vertex Attribute 0 - 3d Vertices
    glEnableVertexAttribArray(0);
    // Bind the VBO to use
    glBindBuffer(GL_ARRAY_BUFFER, vao->VertexBuffer);

    // Enable Vertex Attribute 1 - Color
    glEnableVertexAttribArray(1);
    // Bind the VBO to use
    glBindBuffer(GL_ARRAY_BUFFER, vao->ColorBuffer);

    // Draw the geometry !
    glDrawArrays(vao->PrimitiveMode, 0, vao->NumVertices); // Starting from vertex 0; 3 vertices total -> 1 triangle
}

void construct(VAO x)
{
  float x_temp = (game_board[player.boardx][player.boardy].x+game_board[player.boardx1][player.boardy1].x)/2;
  float y_temp = (game_board[player.boardx][player.boardy].y+game_board[player.boardx1][player.boardy1].y)/2;
  float z_temp;
  if (player_sleep == sleeping_x || player_sleep==sleeping_y)  {  z_temp = game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+2; }
  else z_temp = game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+4;

  glUseProgram (programID);
  if(view_state==adventure)
  {
    Matrices.view = glm::lookAt(glm::vec3(x_temp+2,y_temp,z_temp+5), glm::vec3(x_temp+adventure_radius*cos(adventure_angle*M_PI/180)*cos(adventure_angle_z*M_PI/180),y_temp+adventure_radius*sin(adventure_angle*M_PI/180)*cos(adventure_angle_z*M_PI/180),z_temp+adventure_radius*sin(adventure_angle_z*M_PI/180)), glm::vec3(0,0,1));
    Matrices.projection = glm::perspective(1.57f,1.0f ,1.0f,500.0f);
  }
  else if(view_state==game_view)
  {
    Matrices.view = glm::lookAt(glm::vec3(5*cos(340*M_PI/180)+x_temp,5*sin(340*M_PI/180)+y_temp,z_temp+7), glm::vec3(x_temp,y_temp,z_temp), glm::vec3(0,0,1));
    Matrices.projection = glm::ortho(-25.0f, 25.0f,-25.0f,25.0f, -1.0f, 500.0f);
  }
  else if(view_state==towerview)
  {
    float a_temp = game_board[level[game_level].des.F][level[game_level].des.S].x;
    float b_temp = game_board[level[game_level].des.F][level[game_level].des.S].y;
    float c_temp = game_board[level[game_level].des.F][level[game_level].des.S].z;
    Matrices.view = glm::lookAt(glm::vec3(a_temp,b_temp,20), glm::vec3(a_temp+tower_radius*cos(tower_angle*M_PI/180)*cos(tower_angle_z*M_PI/180),y_temp+tower_radius*sin(tower_angle*M_PI/180)*cos(tower_angle_z*M_PI/180),z_temp+tower_radius*sin(tower_angle_z*M_PI/180)), glm::vec3(0,0,1));
    Matrices.projection = glm::perspective(1.57f,1.0f,1.0f,50.0f);
  }
  else if(view_state==topview)
  {
    Matrices.view = glm::lookAt(glm::vec3(x_temp+1+top_x,y_temp+top_y,z_temp+20), glm::vec3(x_temp+top_x,y_temp+top_y,z_temp), glm::vec3(0,0,1));
    Matrices.projection = glm::ortho(-20.0f, 20.0f,-20.0f,20.0f, -500.0f, 500.0f);
  }
  else if(view_state==followup)
  {
    float a_temp = x_temp;
    float b_temp = y_temp;
    float c_temp = z_temp;
    Matrices.view = glm::lookAt(glm::vec3(5*cos(tower_angle*M_PI/180)+x_temp,5*sin(tower_angle*M_PI/180)+y_temp,z_temp+3), glm::vec3(x_temp,y_temp,z_temp), glm::vec3(0,0,1));
    Matrices.projection = glm::ortho(-15.0f, 15.0f,-15.0f,15.0f, -1.0f, 500.0f);
  }
  else if (view_state == helicopter)
  {
    Matrices.view = glm::lookAt(glm::vec3(5*cos(helic.ang*M_PI/180)+x_temp,5*sin(helic.ang*M_PI/180)+y_temp,z_temp+7), glm::vec3(x_temp,y_temp,z_temp), glm::vec3(0,0,1));
    Matrices.projection = glm::ortho(-25.0f*helic.dis, 25.0f*helic.dis,-25.0f*helic.dis,25.0f*helic.dis, -1.0f, 500.0f);
  }
  glm::mat4 VP = Matrices.projection * Matrices.view;
  glm::mat4 MVP;	// MVP = Projection * View * Model
  Matrices.model = glm::mat4(1.0f);
  glm::mat4 translateobject = glm::translate (glm::vec3(0.0f,0.0f,0.0f)); // glTranslatef
  glm::mat4 rotateobject = glm::rotate((float)(0), glm::vec3(0,0,1));  // rotate about vector (1,0,0)
  glm::mat4 objectsTransform = translateobject * rotateobject;
  Matrices.model *= objectsTransform;
  MVP = VP * Matrices.model; // MVP = p * V * M
  glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
  draw3DObject(&x);
}

#ifndef construct_H_
#define construct_H_


GLuint programID;
float camera_rotation_angle = 90;


struct GLMatrices {

glm::mat4 projection;
	glm::mat4 model;
	glm::mat4 view;
	GLuint MatrixID;
} Matrices;

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat* color_buffer_data,GLenum fill_mode);
struct VAO* create3DObject (GLenum primitive_mode, int numVertices, const GLfloat* vertex_buffer_data, const GLfloat red, const GLfloat green, const GLfloat blue,GLenum fill_mode);
void draw3DObject (struct VAO* vao);
void construct(VAO x);

#include "construct3D.c"
#endif

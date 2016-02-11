#include "line.h"
float vertex1_buffer_data[20];
float color1_buffer_data[20];

VAO* create_line(float x1,float y1,float z1,float x2,float y2,float z2)
{
  int i=0;
  vertex1_buffer_data[i++]=x1; vertex1_buffer_data[i++]=y1; vertex1_buffer_data[i++]=z1;
  vertex1_buffer_data[i++]=x2; vertex1_buffer_data[i++]=y2; vertex1_buffer_data[i++]=z2;
  vertex1_buffer_data[i++]=x1+0.01; vertex1_buffer_data[i++]=y1+0.01; vertex1_buffer_data[i++]=z1+0.01;
  for(i=0;i<12;i++) color1_buffer_data[i++]=0;

  struct VAO* vao = new struct VAO;
  vao = create3DObject(GL_TRIANGLES, 3 , vertex1_buffer_data, color1_buffer_data, GL_LINE);
  return vao;

}

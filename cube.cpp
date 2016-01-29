#include "cube.h"

VAO* create_cube(float x,float y,float z,float l1,float l2,float b1,float b2,float h1,float h2)
{
  GLfloat vertex_buffer_data[200];
  //x+l,y+l,z+h1
  int i=0,j=0;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]=y-b2 ;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x+l1 ;vertex_buffer_data[i++]=y-b1 ;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x+l1 ;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]= y-b2;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]=y+b2 ;vertex_buffer_data[i++]=z+h1 ;
  for(;j<18;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]= x+l1;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]=y-b2 ;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x+l1 ;vertex_buffer_data[i++]=y-b2 ;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x+l1 ;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]= y-b2;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z-h2 ;
  for(;j<18*2;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  for(;j<18*3;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  for(;j<18*4;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  for(;j<18*5;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  for(;j<18*6;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  GLfloat color_buffer_data [200];
  i=0;
  for (;i<18;i++) color_buffer_data[i]=1;
  for (;i<18*2;i++) color_buffer_data[i]=0;
  for (;i<18*3;i++) color_buffer_data[i]=0.5;
  for (;i<18*4;i++) color_buffer_data[i]=0.6;
  for (;i<18*5;i++) color_buffer_data[i]=0.8;
  for (;i<18*6;i++) color_buffer_data[i]=0.2;

  struct VAO* vao = new struct VAO;
  vao = create3DObject(GL_TRIANGLES, 36 , vertex_buffer_data, color_buffer_data, GL_FILL);
  return vao;
}

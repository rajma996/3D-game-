#include "cube.h"
#include "line.h"

float vertex_buffer_data[200];
float vertex_buffer_data_player[200];
vector<VAO> lines;

void set_vertex_buffer(float x,float y,float z,float l1,float l2,float b1,float b2,float h1,float h2)
{
  int i=0,j=0;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]=y-b2 ;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x+l1 ;vertex_buffer_data[i++]=y-b1 ;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x+l1 ;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]= y-b2;vertex_buffer_data[i++]=z+h1 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]=y+b2 ;vertex_buffer_data[i++]=z+h1 ;
  // for(;j<18;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]= x+l1;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]=y-b2 ;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x+l1 ;vertex_buffer_data[i++]=y-b2 ;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x+l1 ;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]= y-b2;vertex_buffer_data[i++]=z-h2 ;
  vertex_buffer_data[i++]=x-l2 ;vertex_buffer_data[i++]=y+b1 ;vertex_buffer_data[i++]=z-h2 ;
  // for(;j<18*2;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  // for(;j<18*3;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  // for(;j<18*4;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y+b1;vertex_buffer_data[i++]=z+h1;
  // for(;j<18*5;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x+l1;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z-h2;
  vertex_buffer_data[i++]=x-l2;vertex_buffer_data[i++]=y-b2;vertex_buffer_data[i++]=z+h1;
  // for(;j<18*6;j+=3) printf("%f %f %f\n",vertex_buffer_data[j],vertex_buffer_data[j+1],vertex_buffer_data[j+2]);

}
void set_vertex_buffer_player(float x,float y,float z,float l1,float l2,float b1,float b2,float h1,float h2)
{
  int i=0,j=0;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y+b1 ;vertex_buffer_data_player[i++]=z+h1 ;
  vertex_buffer_data_player[i++]=x-l2 ;vertex_buffer_data_player[i++]=y-b2 ;vertex_buffer_data_player[i++]=z+h1 ;
  vertex_buffer_data_player[i++]=x+l1 ;vertex_buffer_data_player[i++]=y-b1 ;vertex_buffer_data_player[i++]=z+h1 ;
  vertex_buffer_data_player[i++]=x+l1 ;vertex_buffer_data_player[i++]=y+b1 ;vertex_buffer_data_player[i++]=z+h1 ;
  vertex_buffer_data_player[i++]=x-l2 ;vertex_buffer_data_player[i++]= y-b2;vertex_buffer_data_player[i++]=z+h1 ;
  vertex_buffer_data_player[i++]=x-l2 ;vertex_buffer_data_player[i++]=y+b2 ;vertex_buffer_data_player[i++]=z+h1 ;
  // for(;j<18;j+=3) printf("%f %f %f\n",vertex_buffer_data_player[j],vertex_buffer_data_player[j+1],vertex_buffer_data_player[j+2]);

  vertex_buffer_data_player[i++]= x+l1;vertex_buffer_data_player[i++]=y+b1 ;vertex_buffer_data_player[i++]=z-h2 ;
  vertex_buffer_data_player[i++]=x-l2 ;vertex_buffer_data_player[i++]=y-b2 ;vertex_buffer_data_player[i++]=z-h2 ;
  vertex_buffer_data_player[i++]=x+l1 ;vertex_buffer_data_player[i++]=y-b2 ;vertex_buffer_data_player[i++]=z-h2 ;
  vertex_buffer_data_player[i++]=x+l1 ;vertex_buffer_data_player[i++]=y+b1 ;vertex_buffer_data_player[i++]=z-h2 ;
  vertex_buffer_data_player[i++]=x-l2 ;vertex_buffer_data_player[i++]= y-b2;vertex_buffer_data_player[i++]=z-h2 ;
  vertex_buffer_data_player[i++]=x-l2 ;vertex_buffer_data_player[i++]=y+b1 ;vertex_buffer_data_player[i++]=z-h2 ;
  // for(;j<18*2;j+=3) printf("%f %f %f\n",vertex_buffer_data_player[j],vertex_buffer_data_player[j+1],vertex_buffer_data_player[j+2]);

  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z-h2;
  // for(;j<18*3;j+=3) printf("%f %f %f\n",vertex_buffer_data_player[j],vertex_buffer_data_player[j+1],vertex_buffer_data_player[j+2]);

  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z-h2;
  // for(;j<18*4;j+=3) printf("%f %f %f\n",vertex_buffer_data_player[j],vertex_buffer_data_player[j+1],vertex_buffer_data_player[j+2]);

  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y+b1;vertex_buffer_data_player[i++]=z+h1;
  // for(;j<18*5;j+=3) printf("%f %f %f\n",vertex_buffer_data_player[j],vertex_buffer_data_player[j+1],vertex_buffer_data_player[j+2]);

  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x+l1;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z+h1;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z-h2;
  vertex_buffer_data_player[i++]=x-l2;vertex_buffer_data_player[i++]=y-b2;vertex_buffer_data_player[i++]=z+h1;
  // for(;j<18*6;j+=3) printf("%f %f %f\n",vertex_buffer_data_player[j],vertex_buffer_data_player[j+1],vertex_buffer_data_player[j+2]);

}

// VAO* create_border()
void set_lines(float x,float y,float z,float l1,float l2,float b1,float b2,float h1,float h2)
{
  // lines.clear();
  lines.push_back(*create_line(x+l1,y+b1,z+h1,x+l1,y-b2,z+h1));
  lines.push_back(*create_line(x+l1,y+b1,z+h1,x+l1,y+b1,z-h2));
  lines.push_back(*create_line(x+l1,y+b1,z+h1,x-l2,y+b1,z+h1));

  lines.push_back(*create_line(x+l1,y-b2,z-h2,x+l1,y-b2,z+h1));
  lines.push_back(*create_line(x+l1,y-b2,z-h2,x-l2,y-b2,z-h2));
  lines.push_back(*create_line(x+l1,y-b2,z-h2,x+l1,y+b1,z-h2));

  lines.push_back(*create_line(x-l2,y+b1,z-h2,x-l2,y+b1,z+h1));
  lines.push_back(*create_line(x-l2,y+b1,z-h2,x-l2,y-b2,z-h2));
  lines.push_back(*create_line(x-l2,y+b1,z-h2,x+l1,y+b1,z-h2));

  lines.push_back(*create_line(x-l2,y-b2,z+h1,x-l2,y+b1,z+h1));
  lines.push_back(*create_line(x-l2,y-b2,z+h1,x-l2,y-b2,z-h2));
  lines.push_back(*create_line(x-l2,y-b2,z+h1,x+l1,y-b2,z+h1));

}
VAO* create_cube(float x,float y,float z,float l1,float l2,float b1,float b2,float h1,float h2)
{
  //x+l,y+l,z+h1
  set_lines(x,y,z,l1,l2,b1,b2,h1,h2);
  set_vertex_buffer(x,y,z,l1,l2,b1,b2,h1,h2);
  float color_buffer_data [200];
  int i=0,j=0;
  for (;i<18;i++) if(i%3==1) color_buffer_data[i]=1;
  for (;i<18*2;i++) color_buffer_data[i]=0.8;
  for (;i<18*3;i++) color_buffer_data[i]=0.2;
  for (;i<18*4;i++) color_buffer_data[i]=0.9;
  for (;i<18*5;i++) color_buffer_data[i]=0.1;
  for (;i<18*6;i++) color_buffer_data[i]=0.4;

  struct VAO* vao = new struct VAO;
  vao = create3DObject(GL_TRIANGLES, 36 , vertex_buffer_data, color_buffer_data, GL_FILL);
  return vao;
}
VAO* create_player(float x,float y,float z,float l1,float l2,float b1,float b2,float h1,float h2)
{
  set_vertex_buffer_player(x,y,z,l1,l2,b1,b2,h1,h2);
  // lines.clear();
  // set_lines(x,y,z,l1,l2,b1,b2,h1,h2);
  float color_buffer_data_player [200];
  int i=0,j=0;
  for (;i<18*6;i++) { if(i%3==0) color_buffer_data_player[i]=(float)(0.5); else if(i%3==1) color_buffer_data_player[i]=(float)(0.4); else if(i%3==2) color_buffer_data_player[i]=(float)(0.2); }
  // for (;i<18*2;i++) color_buffer_data_player[i]=0;
  // for (;i<18*3;i++) color_buffer_data_player[i]=0;
  // for (;i<18*4;i++) color_buffer_data_player[i]=0;
  // for (;i<18*5;i++) color_buffer_data_player[i]=0;
  // for (;i<18*6;i++) color_buffer_data_player[i]=0;

  struct VAO* vao = new struct VAO;
  vao = create3DObject(GL_TRIANGLES, 36 , vertex_buffer_data_player, color_buffer_data_player, GL_FILL);
  return vao;

}
VAO* create_water(float x,float y,float z,float l1,float l2,float b1,float b2,float h1,float h2)
{
  set_vertex_buffer(x,y,z,l1,l2,b1,b2,h1,h2);
  float color_buffer_data [200];
  int i=0,j=0;
  for (;i<18*6;) {color_buffer_data[i++]=0; color_buffer_data[i++]=1; color_buffer_data[i++]=2;}
  struct VAO* vao = new struct VAO;
  vao = create3DObject(GL_TRIANGLES, 36 , vertex_buffer_data, color_buffer_data, GL_FILL);
  return vao;

}

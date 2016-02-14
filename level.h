#ifndef level_H
#define level_H

struct level_struct
{
  bool board[50][50];
  pair<int,int>  start;
  pair<int,int>  des;
  vector<pair<int,int> > hbridge;
  vector<pair<int,int> > vbridge;
  vector<vector<pair<int,int> > > hbridge_value;
  vector<vector<pair<int,int> > > vbridge_value;
  vector<VAO> hbridge_vao;
  vector<VAO> vbridge_vao;
 bool board_light[50][50];
};

struct level_struct level[20];
#include "level.cpp"
#endif

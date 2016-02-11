#ifndef level_H
#define level_H

struct level_struct
{
  bool board[50][50];
  pair<int,int>  start;
  pair<int,int>  des;

};

struct level_struct level[20];
#include "level.cpp"
#endif

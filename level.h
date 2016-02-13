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

};

struct level_struct level[20];
#include "level.cpp"
#endif

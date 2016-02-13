#include "level.h"

void set_levels()
{
  loop(i,0,50) loop(j,0,50) level[1].board[i][j]=0;
  loop(i,0,50) loop(j,0,50) level[2].board[i][j]=0;
  loop(i,1,4) level[1].board[1][i]=1;
  loop(i,1,7) level[1].board[2][i]=1;
  loop(i,1,10) level[1].board[3][i]=1;
  loop(i,2,11) level[1].board[4][i]=1;
  loop(i,6,11) level[1].board[5][i]=1;
  loop(i,7,10) level[1].board[6][i]=1;
  level[1].start = MP(2,2);
  level[1].des = MP(5,8);
  loop(i,7,14) level[2].board[1][i]=1;
  loop(i,1,5) level[2].board[2][i]=1; loop(i,7,14) level[2].board[2][i]=1;
  loop(i,1,10) level[2].board[3][i]=1; loop(i,12,16) level[2].board[3][i]=1;
  loop(i,1,5) level[2].board[4][i]=1; loop(i,12,16) level[2].board[4][i]=1;
  loop(i,1,5) level[2].board[5][i]=1; loop(i,12,16) level[2].board[5][i]=1;
  loop(i,13,16) level[2].board[6][i]=1;
  level[2].start = MP(4,2);
  level[2].des = MP(4,14);
  loop(i,2,7) loop(j,1,5) level[3].board[i][j]=1;
  loop(i,1,7) loop(j,7,11) level[3].board[i][j]=1;
  loop(i,1,6) loop(j,13,16) level[3].board[i][j]=1;
  level[3].start = MP(4,2);
  level[3].des = MP(2,14);
  level[3].hbridge.pb(MP(3,3)); level[3].vbridge.pb(MP(2,9));
  vector< pair<int,int> > temp; temp.pb(MP(5,5)); temp.pb(MP(5,6)); level[3].hbridge_value.pb(temp);
    temp.clear(); temp.pb(MP(5,11)); temp.pb(MP(5,12)); level[3].vbridge_value.pb(temp);
}

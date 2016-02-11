#include "level.h"

void set_level0()
{
  loop(i,0,50) loop(j,0,50) level[0].board[i][j]=0;
  loop(i,1,4) level[0].board[1][i]=1;
  loop(i,1,7) level[0].board[2][i]=1;
  loop(i,1,10) level[0].board[3][i]=1;
  loop(i,2,11) level[0].board[4][i]=1;
  loop(i,6,11) level[0].board[5][i]=1;
  loop(i,7,10) level[0].board[6][i]=1;
}

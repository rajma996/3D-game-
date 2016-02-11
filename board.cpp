#include "board.h"

void set_board()
{
  loop(i,-19,21)
  {
    loop(j,-19,21)
    {
      if(level[0].board[i+20][j+20]==1)
      {
        float temp = 5;
        game_board[i+20][j+20].x=(4*(i-1)+2);game_board[i+20][j+20].y=(4*(j-1)+2);game_board[i+20][j+20].z=(0);
        game_board[i+20][j+20].dim.pb(2);game_board[i+20][j+20].dim.pb(2);
        game_board[i+20][j+20].dim.pb(2);game_board[i+20][j+20].dim.pb(2);
        game_board[i+20][j+20].dim.pb(temp);game_board[i+20][j+20].dim.pb(5);
        game_board[i+20][j+20].v=(*create_cube(4*(i-1)+2,4*(j-1)+2,0,2,2,2,2,temp,5));
      }
    }
  }
  water=(*create_water(0,0,-50,1000,1000,1000,1000,45,50));
}
void display_board()
{
  loop(i,-19,21)
  {
    loop(j,-19,21)
    {
      if(level[0].board[i+20][j+20]==1)
      construct(game_board[i+20][j+20].v);
    }
  }
  loop(i,0,lines.size())  construct(lines[i]);
}

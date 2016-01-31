#include "board.h"

void set_board()
{
  loop(i,-4,6)
  {
    loop(j,-4,6)
    {
      if(1)
      {
        float temp = 5+rand()%3;
        printf("%d %d %d %d\n",4*(i-1)+2,4*(j-1)+2,i,j);
        game_board[i+5][j+5].x=(4*(i-1)+2);game_board[i+5][j+5].y=(4*(j-1)+2);game_board[i+5][j+5].z=(0);
        game_board[i+5][j+5].dim.pb(2);game_board[i+5][j+5].dim.pb(2);
        game_board[i+5][j+5].dim.pb(2);game_board[i+5][j+5].dim.pb(2);
        game_board[i+5][j+5].dim.pb(temp);game_board[i+5][j+5].dim.pb(5);
        game_board[i+5][j+5].v=(*create_cube(4*(i-1)+2,4*(j-1)+2,0,2,2,2,2,temp,5));
      }
    }
  }
  water=(*create_water(0,0,-50,1000,1000,1000,1000,45,50));
}
void display_board()
{
  loop(i,1,11)
  {
    loop(j,1,11)
    {
      construct(game_board[i][j].v);
    }
  }
}

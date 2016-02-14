#include "board.h"

void set_board()
{
  lines.clear();
  loop(i,-19,21)
  {
    loop(j,-19,21)
    {
      if(level[game_level].board[i+20][j+20]==1  || level[game_level].board_light[i+20][j+20]==1)
      {
        float temp = 5;
        game_board[i+20][j+20].x=(4*(i-1)+2);game_board[i+20][j+20].y=(4*(j-1)+2);game_board[i+20][j+20].z=(0);
        game_board[i+20][j+20].dim.pb(2);game_board[i+20][j+20].dim.pb(2);
        game_board[i+20][j+20].dim.pb(2);game_board[i+20][j+20].dim.pb(2);
        game_board[i+20][j+20].dim.pb(temp);game_board[i+20][j+20].dim.pb(5);
        if(level[game_level].board[i+20][j+20]==1)
          game_board[i+20][j+20].v=(*create_cube(4*(i-1)+2,4*(j-1)+2,0,2,2,2,2,temp,5));
        else
        {
          printf("%d %d\n",i,j );
          game_board[i+20][j+20].v=(*create_light(4*(i-1)+2,4*(j-1)+2,0,2,2,2,2,temp,5));
        }
      }
    }
  }
  water=(*create_water(0,0,-50,1000,1000,1000,1000,45,50));
  loop(i,0,level[game_level].hbridge.size())
  {
    level[game_level].hbridge_vao.pb  (*create_bridge(game_board[level[game_level].hbridge[i].F][level[game_level].hbridge[i].S].x  ,  game_board[level[game_level].hbridge[i].F][level[game_level].hbridge[i].S].y,game_board[level[game_level].hbridge[i].F][level[game_level].hbridge[i].S].z+6 , 2,2,2,2,1,1,0));
  }
  loop(i,0,level[game_level].vbridge.size())
  {
    level[game_level].vbridge_vao.pb  (*create_bridge(game_board[level[game_level].vbridge[i].F][level[game_level].vbridge[i].S].x  ,  game_board[level[game_level].vbridge[i].F][level[game_level].vbridge[i].S].y,game_board[level[game_level].vbridge[i].F][level[game_level].vbridge[i].S].z+6 , 2,2,2,2,1,1,1));
  }
}
void display_board()
{
  loop(i,-19,21)
  {
    loop(j,-19,21)
    {
      if(i+20==level[game_level].des.F && j+20==level[game_level].des.S) continue;

      if(level[game_level].board[i+20][j+20]==1 || level[game_level].board_light[i+20][j+20]==1)
      construct(game_board[i+20][j+20].v);
    }
  }
  loop(i,0,lines.size())  construct(lines[i]);
  loop(i,0,level[game_level].hbridge_vao.size()) construct(level[game_level].hbridge_vao[i]);
  loop(i,0,level[game_level].vbridge_vao.size()) construct(level[game_level].vbridge_vao[i]);

}

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
          // printf("%d %d\n",i,j );
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
void set_alllines()
{
  lines.clear();
  loop(i,-19,21)
  {
    loop(j,-19,21)
    {
      if(level[game_level].board[i+20][j+20]==1  || level[game_level].board_light[i+20][j+20]==1)
        set_lines(game_board[i+20][j+20].x,game_board[i+20][j+20].y,game_board[i+20][j+20].z,game_board[i+20][j+20].dim[0],game_board[i+20][j+20].dim[1],game_board[i+20][j+20].dim[2],game_board[i+20][j+20].dim[3],game_board[i+20][j+20].dim[4],game_board[i+20][j+20].dim[5]);
    }
  }
}
void change_tiles()
{
  int x=rand()%40-19; int y=rand()%40-19;
  if(rand()%4!=0) return ;
  if(level[game_level].board[x+20][y+20]==1 || level[game_level].board_light[x+20][y+20] )
  {
    if ( (x+20==level[game_level].start.F && y+20== level[game_level].start.S) ||  (x+20==level[game_level].des.F && y+20== level[game_level].des.S) ) return;
    if(level[game_level].board[x+20][y+20]==1)
    {
      game_board[x+20][y+20].v=(*create_cube(4*(x-1)+2,4*(y-1)+2,0,2,2,2,2,8,5)); game_board[x+20][y+20].dim[4]=8;
    }
    else if(level[game_level].board_light[x+20][y+20]==1)
    {
      game_board[x+20][y+20].v=(*create_light(4*(x-1)+2,4*(y-1)+2,0,2,2,2,2,8,5)); game_board[x+20][y+20].dim[4]=8;
    }
  }
  printf("set : %d %d\n",x+20,y+20 );
  level[game_level].up_tiles.pb(MP(x,y));
  set_alllines();
  if(level[game_level].up_tiles.size()<2) return;
  int i = level[game_level].up_tiles[0].F; int j = level[game_level].up_tiles[0].S;
  printf("unset : %d %d\n",i+20,j+20 );

  if(level[game_level].board[i+20][j+20]==1 || level[game_level].board_light[i+20][j+20] )
  {
    if(level[game_level].board[i+20][j+20]==1)
    {
      game_board[i+20][j+20].v=(*create_cube(4*(i-1)+2,4*(j-1)+2,0,2,2,2,2,5,5)); game_board[i+20][j+20].dim[4]=5;
    }
    else if(level[game_level].board_light[i+20][j+20]==1)
    {
      game_board[i+20][j+20].v=(*create_light(4*(i-1)+2,4*(j-1)+2,0,2,2,2,2,5,5)); game_board[i+20][j+20].dim[4]=5;
    }
  }

  loop(i,1,level[game_level].up_tiles.size())
  {
    level[game_level].up_tiles[i-1] = level[game_level].up_tiles[i];
  }
  level[game_level].up_tiles.pop_back();
}

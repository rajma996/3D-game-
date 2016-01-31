#include "player.h"



void init_player()
{
  player.boardx = 1;
  player.boardy = 1;
  // printf("%f %d %d %f\n",game_board[player.boardx][player.boardy].dim[4],player.boardx,player.boardy,game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+2);
  player.v.pb(*create_player(game_board[1][1].x,game_board[1][1].y,game_board[1][1].z+game_board[1][1].dim[4]+1,1,1,1,1,1,1));
}
void display_player()
{
  construct(player.v[0]);
}
void move_player_xp()
{
  if(player.boardx<10)
  {
    player.boardx++;
    player.v[0]=(*create_player(game_board[player.boardx][player.boardy].x,game_board[player.boardx][player.boardy].y,game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+1,1,1,1,1,1,1));
  }
}
void move_player_yp()
{
  if(player.boardy<10)
  {
    player.boardy++;
    player.v[0]=(*create_player(game_board[player.boardx][player.boardy].x,game_board[player.boardx][player.boardy].y,game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+1,1,1,1,1,1,1));
  }
}
void move_player_xm()
{
  if(player.boardx>1)
  {
    player.boardx--;
    player.v[0]=(*create_player(game_board[player.boardx][player.boardy].x,game_board[player.boardx][player.boardy].y,game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+1,1,1,1,1,1,1));
  }
}
void move_player_ym()
{
  if(player.boardy>1)
  {
    player.boardy--;
    player.v[0]=(*create_player(game_board[player.boardx][player.boardy].x,game_board[player.boardx][player.boardy].y,game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+1,1,1,1,1,1,1));
  }
}

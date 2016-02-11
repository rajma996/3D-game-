#include "player.h"



void init_player()
{
  player.boardx = 1;
  player.boardy = 1;
  player.boardx1 = 1;
  player.boardy1 = 1;
  player.v.pb(*create_player(game_board[1][1].x,game_board[1][1].y,game_board[1][1].z+game_board[1][1].dim[4]+4,2,2,2,2,4,4));
}
void display_player()
{
  construct(player.v[0]);
}
void constplayer()
{
  float x_size,y_size,z_size;
  if(player_sleep == standing) { x_size=2;  y_size=2; z_size=4; }
  else if(player_sleep == sleeping_x ) { x_size=4; y_size=2; z_size=2;  }
  else if(player_sleep == sleeping_y ) { x_size=2; y_size=4; z_size=2;  }
  float x_temp = (game_board[player.boardx][player.boardy].x+game_board[player.boardx1][player.boardy1].x)/2;
  float y_temp = (game_board[player.boardx][player.boardy].y+game_board[player.boardx1][player.boardy1].y)/2;
  float z_temp;
  if (player_sleep == sleeping_x || player_sleep==sleeping_y)  {  z_temp = game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+2; }
  else z_temp = game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+4;

  player.v[0]=(*create_player(x_temp,y_temp,z_temp,x_size,x_size,y_size,y_size,z_size,z_size));

}
void move_player_up()
{
  if(player_state == xplus)
  {
    if(player_sleep == standing )  { player_sleep = sleeping_x; player.boardx++; player.boardx1+=2;  }
    else if(player_sleep==sleeping_x) { player_sleep=standing; player.boardx+=2; player.boardx1++;  }
    else if(player_sleep==sleeping_y) { player.boardx++; player.boardx1++; }
  }
  constplayer();
}
void move_player_down()
{
  if(player_state == xplus)
  {
    if(player_sleep == standing )  { player_sleep = sleeping_x; player.boardx-=2; player.boardx1--;  }
    else if(player_sleep==sleeping_x) { player_sleep=standing; player.boardx--; player.boardx1-=2;  }
    else if(player_sleep==sleeping_y) { player.boardx--; player.boardx1--; }
  }
  constplayer();
}
void move_player_left()
{
  if(player_state==xplus)
  {
    if(player_sleep == standing) { player_sleep = sleeping_y; player.boardy++; player.boardy1+=2; }
    else if(player_sleep == sleeping_x) { player.boardy++; player.boardy1++;  }
    else if(player_sleep == sleeping_y) {player_sleep = standing ; player.boardy+=2; player.boardy1++;}
  }
  constplayer();
}
void move_player_right()
{
  if(player_state==xplus)
  {
    if(player_sleep == standing) { player_sleep = sleeping_y; player.boardy-=2; player.boardy1--; }
    else if(player_sleep == sleeping_x) { player.boardy--; player.boardy1--;  }
    else if(player_sleep == sleeping_y) {player_sleep = standing ; player.boardy--; player.boardy1-=2;}
  }
  constplayer();
}

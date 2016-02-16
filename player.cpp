#include "player.h"



void init_player()
{
  player.boardx = level[game_level].start.F;
  player.boardy = level[game_level].start.S;
  player.boardx1 = level[game_level].start.F;
  player.boardy1 = level[game_level].start.S;
  player_sleep=standing;
  float x_temp = (game_board[player.boardx][player.boardy].x+game_board[player.boardx1][player.boardy1].x)/2;
  float y_temp = (game_board[player.boardx][player.boardy].y+game_board[player.boardx1][player.boardy1].y)/2;
  float z_temp;
  if (player_sleep == sleeping_x || player_sleep==sleeping_y)  {  z_temp = game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+2; }
  else z_temp = game_board[player.boardx][player.boardy].z+game_board[player.boardx][player.boardy].dim[4]+4;


  float x_size,y_size,z_size;
  if(player_sleep == standing) { x_size=2;  y_size=2; z_size=4; }
  else if(player_sleep == sleeping_x ) { x_size=4; y_size=2; z_size=2;  }
  else if(player_sleep == sleeping_y ) { x_size=2; y_size=4; z_size=2;  }
  // printf("%d %d %d\n",game_level,level[game_level].start.F,level[game_level].start.S);
  if(player.v.size()==0)
    player.v.pb(*create_player(x_temp,y_temp,z_temp,x_size,x_size,y_size,y_size,z_size,z_size));
  else
    player.v[0]=(*create_player(x_temp,y_temp,z_temp,x_size,x_size,y_size,y_size,z_size,z_size));
  construct(player.v[0]);
}
void display_player()
{
  construct(player.v[0]);
}
void constplayer()
{
  if( level[game_level].board[player.boardx][player.boardy]==0 || level[game_level].board[player.boardx1][player.boardy1]==0)
  {
    if( level[game_level].board_light[player.boardx][player.boardy]==0 || level[game_level].board_light[player.boardx1][player.boardy1]==0)
     { cout<<"You have died take care"<<endl; keys[GLFW_KEY_Q]=1; return ;}
   }
  if( level[game_level].board_light[player.boardx][player.boardy]==1 || level[game_level].board_light[player.boardx1][player.boardy1]==1)
  {
    if(player_sleep == standing)
    {
       cout<<"You have died take care you can only sleep on light tiles"<<endl; keys[GLFW_KEY_Q]=1; return ;
     }
  }
  else if(player_sleep==standing && player.boardx==level[game_level].des.F && player.boardy==level[game_level].des.S) {game_level++;set_board();  init_player(); return ;}
  loop(i,0,level[game_level].hbridge.size())
  {
    if((player.boardx==level[game_level].hbridge[i].F || player.boardx1==level[game_level].hbridge[i].F)  && ( player.boardy==level[game_level].hbridge[i].S || player.boardy1==level[game_level].hbridge[i].S))
    {
      loop(j,0,level[game_level].hbridge_value[i].size())
      {
        level[game_level].board[level[game_level].hbridge_value[i][j].F][level[game_level].hbridge_value[i][j].S]=1;
      }
      set_board();
    }
  }
  loop(i,0,level[game_level].vbridge.size())
  {
    if((player.boardx==level[game_level].vbridge[i].F || player.boardx1==level[game_level].vbridge[i].F)  && ( player.boardy==level[game_level].vbridge[i].S || player.boardy1==level[game_level].vbridge[i].S) && player_sleep==standing)
    {
      loop(j,0,level[game_level].vbridge_value[i].size())
      {
        level[game_level].board[level[game_level].vbridge_value[i][j].F][level[game_level].vbridge_value[i][j].S]=1;
      }
      set_board();
    }
  }
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
void move_player_down()
{
  if(player_state == xplus)
  {
    if(player_sleep == standing )  { player_sleep = sleeping_x; player.boardx++; player.boardx1+=2;  }
    else if(player_sleep==sleeping_x) { player_sleep=standing; player.boardx+=2; player.boardx1++;  }
    else if(player_sleep==sleeping_y) { player.boardx++; player.boardx1++; }
  }
  constplayer();
}
void move_player_up()
{
  if(player_state == xplus)
  {
    if(player_sleep == standing )  { player_sleep = sleeping_x; player.boardx-=2; player.boardx1--;  }
    else if(player_sleep==sleeping_x) { player_sleep=standing; player.boardx--; player.boardx1-=2;  }
    else if(player_sleep==sleeping_y) { player.boardx--; player.boardx1--; }
  }
  constplayer();
}
void move_player_right()
{
  if(player_state==xplus)
  {
    if(player_sleep == standing) { player_sleep = sleeping_y; player.boardy++; player.boardy1+=2; }
    else if(player_sleep == sleeping_x) { player.boardy++; player.boardy1++;  }
    else if(player_sleep == sleeping_y) {player_sleep = standing ; player.boardy+=2; player.boardy1++;}
  }
  constplayer();
}
void move_player_left()
{
  if(player_state==xplus)
  {
    if(player_sleep == standing) { player_sleep = sleeping_y; player.boardy-=2; player.boardy1--; }
    else if(player_sleep == sleeping_x) { player.boardy--; player.boardy1--;  }
    else if(player_sleep == sleeping_y) {player_sleep = standing ; player.boardy--; player.boardy1-=2;}
  }
  constplayer();
}

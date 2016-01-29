#include "board.h"

void set_board()
{
  loop(i,1,5)
  {
    loop(j,1,5)
    {
      board.pb(*create_cube(i,j,0,1,1,5+rand()%3,5));
    }
  }
}

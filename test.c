#include <stdio.h>
#include "2048.h"

int line_vector_test(char *s1, int i1,int i2,int i3,int i4,char *msg,
                int o1,int o2,int o3,int o4, int (*func)(int,int *))
{
  int list[4]={i1,i2,i3,i4};
  if (msg) printf("%s - ",msg); 
  else {
    printf("Tilting {%d,%d,%d,%d} %s yields {%d,%d,%d,%d} - ",
             i1,i2,i3,i4,s1,o1,o2,o3,o4);
  }
  fflush(stdout);
  func(4,list);
  if ((list[0]!=o1)||(list[1]!=o2)||(list[2]!=o3)||(list[3]!=o4))
    {
      printf("FAILED:\n {%d,%d,%d,%d} became {%d,%d,%d,%d} instead of"
             " {%d,%d,%d,%d}\n",
             i1,i2,i3,i4,list[0],list[1],list[2],list[3],
             o1,o2,o3,o4);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
  
}

int ttl_vector(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
  return line_vector_test("left",i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_left);
}

int ttr_vector(int i1,int i2,int i3,int i4,char *msg,
               int o1,int o2,int o3,int o4)
{
  return line_vector_test("right",i1,i2,i3,i4,msg,o1,o2,o3,o4,tilt_line_right);
}

int line_vector_test2(char *s1, int i1,int i2,int i3,int i4,
                int o1, int (*func)(int,int *))
{
  int list[4]={i1,i2,i3,i4};
    printf("Tilting {%d,%d,%d,%d} %s returns %d - ",
             i1,i2,i3,i4,s1,o1);
  fflush(stdout);
  int o2 =func(4,list);
  if (o2!=o1)
    {
      printf("FAILED:\n {%d,%d,%d,%d} returns %d instead of"
             " %d \n",
             i1,i2,i3,i4,o2,o1);
      return -1;
    } 
  printf("PASSED.\n");
  return 0;
}

int ttl_vector2(int i1,int i2,int i3,int i4,
               int o1)
{
  return line_vector_test2("left",i1,i2,i3,i4,o1,tilt_line_left);
}
int ttr_vector2(int i1,int i2,int i3,int i4,
               int o1)
{
  return line_vector_test2("right",i1,i2,i3,i4,o1,tilt_line_right);
}

int test_tilt_left()
{
  int e=0;
  e|=ttl_vector(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttl_vector(1,0,0,0,"Value on left stays on left after shift",1,0,0,0);
  e|=ttl_vector(0,0,0,1,"Value on right shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(0,0,1,0,"Value in middle shifts to left edge after shift",1,0,0,0);
  e|=ttl_vector(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttl_vector(1,1,1,1,"Combinations don't cascade",2,2,0,0);
  e|=ttl_vector(0,0,1,1,NULL,2,0,0,0);
  e|=ttl_vector(4,0,1,1,NULL,4,2,0,0);
  e|=ttl_vector(2,0,1,1,NULL,2,2,0,0);
  e|=ttl_vector(2,1,1,0,NULL,2,2,0,0);
  e|=ttl_vector(1,1,2,0,NULL,2,2,0,0);
  return e;
}

int test_tilt_right()
{
  int e=0;
  e|=ttr_vector(0,0,0,0,"Empty list is empty after shift",0,0,0,0);
  e|=ttr_vector(0,0,0,1,"Value on right stays on right after shift",0,0,0,1);
  e|=ttr_vector(1,0,0,0,"Value on left shifts to right edge after shift",0,0,0,1);
  e|=ttr_vector(0,0,1,0,"Value in middle shifts to right edge after shift",0,0,0,1);
  e|=ttr_vector(1,2,4,8,"Distinct values don't combine",1,2,4,8);
  e|=ttr_vector(1,1,1,1,"Combinations don't cascade",0,0,2,2);
  e|=ttr_vector(1,1,0,0,NULL,0,0,0,2);
  e|=ttr_vector(1,1,0,4,NULL,0,0,2,4);
  e|=ttr_vector(1,1,0,2,NULL,0,0,2,2);
  e|=ttr_vector(0,2,1,1,NULL,0,0,2,2);
  return e;
}

int test_board_spawn()
{
  int e =0;
  int board_size=4;
  int **board=board_create(board_size);
  printf("Spawn 1: \n");
  e|= board_spawn_tile(board_size,board);
  board_display(board_size,board);
  printf("spawn 2: \n");
  e|= board_spawn_tile(board_size,board);
  board_display(board_size,board);
  printf("spawn 3: \n");
  e|= board_spawn_tile(board_size,board);
  board_display(board_size,board);
  return e;
}

int test_board_tilt()
{
  int e =0;
  int ** board=board_create(4);
  board_spawn_tile(4,board);
  board_spawn_tile(4,board);
  board_spawn_tile(4,board);
  board_spawn_tile(4,board);
  printf("Original board: \n");
  board_display(4,board);
  board=board_flip(board,4);
  printf("Flip 1: \n");
  board_display(4,board);
  board=board_flip(board,4);
  printf("Flip 2: \n");
  board_display(4,board);
  return e;
}

int test_final_board()
{
  int board_size=4;
  int i;
  int **board=board_create(board_size);
board_spawn_tile(board_size,board);
board_spawn_tile(board_size,board);
  while(empty(board_size,board)||board_tiltable(board_size, board)){
      board=board_flip(board,board_size);
      for(i=0;i<board_size;i++) tilt_line_left(board_size,board[i]);
      board=board_flip(board,board_size);
      board_spawn_tile(board_size,board);
      board=board_flip(board,board_size);
      for(i=0;i<board_size;i++) tilt_line_right(board_size,board[i]);
      board=board_flip(board,board_size);
      board_spawn_tile(board_size,board);
      for(i=0;i<board_size;i++) tilt_line_left(board_size,board[i]);
      board_spawn_tile(board_size,board);
      for(i=0;i<board_size;i++) tilt_line_right(board_size,board[i]);
      board_spawn_tile(board_size,board);
  }
  printf("Final board:\n");
  board_display(4,board);
  return 0;
}

int test_tilted_right(){
  int e=0;
  e|=ttr_vector2(0,1,1,0,1);
  e|=ttr_vector2(2,1,0,0,1);
  e|=ttr_vector2(2,2,0,0,1);
  e|=ttr_vector2(0,0,0,0,0);
  e|=ttr_vector2(8,4,2,1,0);
  e|=ttr_vector2(0,0,2,1,0);
  return e;
}
int test_tilted_left(){
  int e=0;
  e|=ttl_vector2(0,1,1,0,1);
  e|=ttl_vector2(2,1,0,0,0);
  e|=ttl_vector2(2,2,0,0,1);
  e|=ttl_vector2(0,0,0,0,0);
  e|=ttl_vector2(8,4,2,1,0);
  e|=ttl_vector2(0,0,2,1,1);
  return e;
}
int main(int argc,char **argv)
{
  int e=0;
  printf("Left tilting:\n");
  e|=test_tilt_left();
  printf("\nRight tilting:\n");
  e|=test_tilt_right();
  printf("\nRight tilted:\n");
  e|=test_tilted_right();
  printf("Left tilted:\n");
  e|=test_tilted_left();
  e|=test_final_board();
  e|=test_board_spawn();
  e|=test_board_tilt();
  return e;
}

#include <stdio.h>
#include <stdlib.h>
#include "2048.h"
#include <time.h>
#define srandom srand

int **board_create(int size)
{
  int i;
  // make sure size of board is sensible
  if (size<1||size>255) return NULL;

  int **board=calloc(size,sizeof(int *));
  if (!board) return NULL;
  for(i=0;i<size;i++) {
    board[i]=calloc(size,sizeof(int));
    if (!board[i]) return NULL;
  }
  return board;
}

int **board_flip(int **board, int size){
  if (size<1||size>255) return NULL;
  if (!board) return NULL;
  int **board_temp=board_create(size);
  int x,y;
  for(x=0;x<size;x++){
    for(y=0;y<size;y++){
      board_temp[x][y]=board[y][x];   
    }
  }
  return board_temp;
  
}

int board_display(int size,int **board)
{
  // make sure size of board is sensible
  if (size<1||size>255) return -1;
  
  int x,y;
  
  for(y=0;y<size;y++) {    
    for(x=0;x<size;x++) {
      if (board[x][y]) printf("[% 5d]",board[x][y]);
      else printf("[     ]");
    }
    printf("\n");
  }
  return 0;
}

int empty(int size, int**board){
  int count = 0;
  int x,y;
  for(y=0;y<size;y++) {    
    for(x=0;x<size;x++) {
      if (!board[x][y]) count++;
    }
  }
  return count;
}

int board_spawn_tile(int size,int **board){
  srand(time(NULL));
  int count,x,y,r;
  count = empty(size,board);
  if(count){
  r = rand() % (count);
  for(y=0;y<size;y++) {    
    for(x=0;x<size;x++) {
      if(!board[x][y]){
        if (r) r--;
        else{
          srand((x+1)*(y+1)*time(NULL));
          int random = rand()%10 +1;
          board[x][y]=(random < 8 ? 2 : 4);
          x=size;
          y=size;
        }
      }
    }
  }
}
  return 0;
}

int board_moveable(int board_size, int** board){
  int i,x,y;
  int different=0;
      int **board_test_l=board_clone(board_size,board);
      board_test_l=board_flip(board_test_l,board_size);

      for(i=0;i<board_size;i++) tilt_line_left(board_size,board_test_l[i]);
      board_test_l=board_flip(board_test_l,board_size);
      
      int **board_test_u=board_clone(board_size,board);

      for(i=0;i<board_size;i++) tilt_line_left(board_size,board_test_u[i]);
      for(x=0;x<board_size;x++){
        for(y=0;y<board_size;y++){
          if(board[x][y]!=board_test_u[x][y]||board[x][y]!=board_test_l[x][y]) {different++;x=board_size;y=board_size;}
        }
      }
      if(!different) {return 0;}
    
    return 1;
}

int** board_clone(int board_size, int** board){
  int**board2=board_create(board_size);
  int x,y;
  for (x=0;x<board_size;x++){
    for(y=0;y<board_size;y++){
      board2[x][y]=board[x][y];
    }
  }
  return board2;
}
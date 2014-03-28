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

int board_spawn_tile(int size,int **board){
  srand(time(NULL));
  int count = 0;
  int x,y;
  for(y=0;y<size;y++) {    
    for(x=0;x<size;x++) {
      if (!board[x][y]) count++;
    }
  }
  int r =rand() % (count-1);
  for(y=0;y<size;y++) {    
    for(x=0;x<size;x++) {
      if(!board[x][y]){
        if (r) r--;
        else{
          srand((x+1)*(y+1)*time(NULL));
          int random = rand()%2 +1;
          board[x][y]=2*(random);
          x=size;
          y=size;
        }
      }
    }
  }
  return 0;
}

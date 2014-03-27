#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;
  int i;
  for (i=length-1;i>1;i--){
  	if(line[i-1]=0){
  		line[i-1]=line[i];
  		line[i]=0;
  		i--;
  	}
  	else if(line[i-1]=line[i]){
  		line[i-1]*=2;
  		line[i]=0;
  		i--;
  	}
  }
  // slide tiles to the left

  // combine tiles as required

  return 0;
}

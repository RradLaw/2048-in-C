#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  int i,j;
  for (i=0;i<length;i++){
  	if(!line[i]){
      for(j=i+1;j<length;j++){
        if(line[j]){
          line[i]=line[j];
          line[j]=0;
          j=length;
        }
      }
  	} 
  }

  // combine tiles as required
    for(i=0;i<length;i++){
    if(line[i]==line[i+1]){
      line[i]=2*line[i];
      line[i+1]=0;
    }
  }


  return 0;
}

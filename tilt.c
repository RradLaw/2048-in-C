#include <stdio.h>
#include "2048.h"

int tilt_line_left(int length,int *line)
{
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the left
  int i,j,shift;
  int tilted=0;
  int merged=0;
  for (i=0;i<length;i++){
    shift=0;
  	if(!line[i]){
      for(j=i+1;j<length;j++){
        if(line[j]){
          line[i]=line[j];
          line[j]=0;
          j=length;
          shift++;
          tilted=1;
        }
      }
  	}
  // combine tiles as required
    if(shift) i--;
    if(line[i]==line[i+1]&&!merged&&line[i]){
      line[i]=2*line[i];
      line[i+1]=0;
      merged=1;
      tilted=1;
    }else merged=0;
  } 
  return tilted;//not working
}

int tilt_line_right(int length,int *line){
  // make sure vector length is sensible
  if (length<1||length>255) return -1;

  // slide tiles to the right
  int i,j,shift;
  int tilted=0;
  int merged=0;
  for (i=length-1;i>=0;i--){
    shift=0;
    if(!line[i]){
      for(j=i-1;j>=0;j--){
        if(line[j]){
          line[i]=line[j];
          line[j]=0;
          j=0;
          shift++;
          tilted=1;
        }
      }
    }
  // combine tiles as required
    if(shift) i++;
    if(line[i]==line[i-1]&&!merged&&line[i]){
      line[i]=2*line[i];
      line[i-1]=0;
      merged=1;
      tilted=1;
    } else merged=0;
  } 
  return tilted;
}
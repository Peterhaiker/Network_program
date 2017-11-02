/*
 * judge_bigsmall_endian.c
 * Copyright (C) 2017-11-02 23:10 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include "stdio.h"

int main(int argc,char*argv[])
{
  union{
    short s;
    char c[sizeof(short)];
  }un;
  un.s=0x0102;
  if(sizeof(short)==2){
    if(un.c[0]==1&&un.c[1]==2)
      printf("big-endian\n");
    else if(un.c[0]==2&&un.c[1]==1)
      printf("litter-endian\n");
    else
      printf("unknown\n");
  }
  else
    printf("sizeof(short)=%d\n",sizeof(short));
  return 0;
}

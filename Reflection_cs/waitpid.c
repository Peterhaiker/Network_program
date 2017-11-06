/*
 * wait.c
 * Copyright (C) 2017-11-04 23:55 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include "stdio.h"
#include"unp.h"

void sig_chld(int signo)
{
  pid_t pid;
  int stat;
  while((pid=waitpid(-1,&stat,WNOHANG))>0)
    printf("child %d terminated\n",pid);
  return;
}

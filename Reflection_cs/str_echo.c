/*
 * str_echo.c
 * Copyright (C) 2017-11-04 21:11 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include "stdio.h"
#include"myecho.h"
#include"unp.h"
#include<unistd.h>
#include<errno.h>

void str_echo(int sockfd)
{
  errno=0;
  ssize_t n;
  char buf[MAXLINE];
again:
  while((n=read(sockfd,buf,MAXLINE))>0)
    writen(sockfd,buf,n);

  if(n<0&&errno==EINTR)
    goto again;
  else if(n<0){
    perror("str_echo:read error");
    return;
  }
  return;
}

/*
 * str_echov01.c
 * Copyright (C) 2017-11-07 10:26 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include "stdio.h"
#include"unp.h"

void str_echo(int sockfd)
{
  ssize_t n;
  char buf[MAXLINE];
again:
  while((n=read(sockfd,buf,MAXLINE))>0)
    Writen(sockfd,buf,n);
  if(n<0&&errno==EINTR)
    goto again;
  else if(n<0)
    err_sys("str_echo:read error");
  return 0;
}

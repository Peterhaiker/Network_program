/*
 * str_cli.c
 * Copyright (C) 2017-11-04 22:41 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include "stdio.h"
#include"unp.h"

void str_cli(FILE*fp,int sockfd)
{
  char sendline[MAXLINE],recvline[MAXLINE];
  while(Fgets(sendline,MAXLINE,fp)!=NULL){
    Writen(sockfd,sendline,strlen(sendline));
    if(Readline(sockfd,recvline,MAXLINE)==0)
      err_quit("str_cli:server terminated prematurely");
    Fputs(recvline,stdout);
  }
  return;
}

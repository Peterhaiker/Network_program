/*
 * tcpserv01.c
 * Copyright (C) 2017-11-04 20:57 
 * author  Peterhaiker 
 * email   <vim.memory@gmail.com>
 *
 * description:
 */

#include "stdio.h"
#include"myecho.h"
#include<strings.h>
#include"unp.h"
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>

int main(int argc,char*argv[])
{
  int listenfd,connfd;
  pid_t childpid;
  socklen_t clilen;
  struct sockaddr_in cliaddr,servaddr;

  listenfd=socket(AF_INET,SOCK_STREAM,0);
  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_family=AF_INET;
  servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
  servaddr.sin_port=htons(SERV_PORT);
  bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
  Signal(SIGCHLD,sig_chld);
  listen(listenfd,LISTENQ);

  for(;;){
    clilen=sizeof(cliaddr);
    connfd=accept(listenfd,(struct sockaddr*)&cliaddr,&clilen);
    if((childpid=fork())==0){
      close(listenfd);
      str_echo(connfd);
      exit(0);
    }
    close(connfd);
  }
  return 0;
}

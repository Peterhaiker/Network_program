srvobjects= tcpserv04.o waitpid.o str_echo.o
cliobjects=tcpcli04.o str_cli.o
all:tcpserv04 tcpcli04
.PHONY:all

tcpserv04:$(srvobjects)
	gcc -o tcpserv04 $(srvobjects) -lunp#$@表示所有目标集 $<表示所有依赖目标集
tcpserv04.o:tcpserv04.c myecho.h
waitpid.o:waitpid.c myecho.h
str_echo.o:str_echo.c myecho.h  #上面三行利用了make的自动推导功能

tcpcli04:$(cliobjects)
	gcc -o tcpcli04 $(cliobjects)
tcpcli04.o:tcpcli04.c str_cli.c
str_cli.o:str_cli.c

.PHONY:clean
clean:
	@rm *.o *.i *.s tcpserv04 tcpcli04

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include<errno.h>
#include<signal.h>
#include<wait.h>

#define MAXLEN 1024
#define PORT 9877

void err_quit(const char *s);
void strecho(int sockfd);
void sig_chld(int signo);
int main(int grgc,char **argv)
{
	int listenfd,connectfd;
	struct sockaddr_in cliaddr,servaddr;
	socklen_t clilen;
	pid_t childpid;
	
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	if(listenfd<0)
		err_quit("socket error");
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORT);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	listen(listenfd,1024);
	signal(SIGCHLD,sig_chld);
	for(;;)
	{
		clilen=sizeof(cliaddr);
		connectfd=accept(listenfd,(struct sockaddr *)&cliaddr,&clilen);
		if(connectfd<0)
		{
			if(errno==EINTR)
				continue;
			else
				err_quit("accept error");
		}
		if((childpid=fork())==0)
		{
			close(listenfd);
			strecho(connectfd);
			exit(0);
		}
		close(connectfd);
	}
}
void sig_chld(int signo)
{
	pid_t pid;
	int stat;
	while((pid=waitpid(-1,&stat,WNOHANG))>0)
		printf("child %d terminatied\n",pid);
	return;
}
void strecho(int sockfd)
{
/*	char buf[MAXLEN];*/
/*	size_t n=0;*/
/*	for(;;)*/
/*	{*/
/*		n=read(sockfd,buf,MAXLEN);*/
/*		if(n<0&&errno==EINTR)*/
/*			continue;*/
/*		else if(n<0)*/
/*			err_quit("strecho:read error.");*/
/*		buf[n]=0;*/
/*		write(sockfd,buf,strlen(buf));*/
/*	}*/
	ssize_t n;
	char buf[MAXLEN];
again:
	while((n=read(sockfd,buf,MAXLEN))>0)
		write(sockfd,buf,n);
	if(n<0&&errno==EINTR)
		goto again;
	else if(n<0)
		err_quit("str_echo:read error");
}
void err_quit(const char *s)
{
	printf("%s\n",s);
	exit(0);
}

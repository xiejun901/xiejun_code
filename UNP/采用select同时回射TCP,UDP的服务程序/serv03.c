#include"my_unp.h"
#include<sys/select.h>
#include<errno.h>
#include<wait.h>
#include<signal.h>
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

void dg_echo(int sockfd,struct sockaddr * pcliaddr,size_t clilen);
void strecho(int connectfd);
void sig_chld(int signo);
int main()
{
	struct sockaddr_in servaddr,cliaddr;
	int nready;//select时已经准备好的描述符
	socklen_t clilen;
	int sockfd_udp;//udp套接字
	int sockfd_tcp;//tcp监听套接字
	int connectfd;//连接的套接字
	int maxfdp1;
	fd_set rset;
	pid_t childpid;
	const int on=1;
	
	sockfd_tcp=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd_tcp<0)
		err_quit("socket tcp error");
	//服务器地址端口
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORTNO);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	setsockopt(sockfd_tcp,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
	if(bind(sockfd_tcp,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
		err_quit("sockfd_tcp bind error");
	if(listen(sockfd_tcp,1024)<0)
		err_quit("tcp listen error");
	
	
	sockfd_udp=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd_udp<0)
		err_quit("socket udp error");
		
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORTNO);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	if(bind(sockfd_udp,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
		err_quit("sockfd_udp bind error");
	
	maxfdp1=max(sockfd_tcp,sockfd_udp)+1;
	FD_ZERO(&rset);
	
	signal(SIGCHLD,sig_chld);
	for(;;)
	{
		FD_SET(sockfd_tcp,&rset);
		FD_SET(sockfd_udp,&rset);
		nready=select(maxfdp1,&rset,NULL,NULL,NULL);
		if(nready<0)
		{
			if(errno==EINTR)
				continue;
			else
				err_quit("select error");
		}
		if(FD_ISSET(sockfd_tcp,&rset))
		{
			clilen=sizeof(cliaddr);
			connectfd=accept(sockfd_tcp,(struct sockaddr *)&cliaddr,&clilen);
			if(connectfd<0)
				err_quit("accept error");
			if((childpid=fork())==0)
			{
				close(sockfd_tcp);
				strecho(connectfd);
				exit(0);
			}
			close(connectfd);
			if(--nready==0)
				continue;
		}
		if(FD_ISSET(sockfd_udp,&rset))
		{
			dg_echo(sockfd_udp,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
		}
	}	
}

void dg_echo(int sockfd,struct sockaddr * pcliaddr,size_t clilen)
{
	int n=0;
	socklen_t len;
	char msg[MAXLEN];
	len=clilen;
	n=recvfrom(sockfd,msg,MAXLEN,0,pcliaddr,&len);
	if(n<0)
		err_quit("udp recvfrom error");
	if(sendto(sockfd,msg,n,0,pcliaddr,len)<0)
		err_quit("udp sendto error");
}
void strecho(int sockfd)
{
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

void sig_chld(int signo)
{
	pid_t pid;
	int stat;
	while((pid=waitpid(-1,&stat,WNOHANG))>0)
		printf("child %d terminatied\n",pid);
	return;
}

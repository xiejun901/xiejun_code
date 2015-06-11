#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/select.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

#define MAXLEN 1024
void err_quit(const char *s);
void clistr(FILE *fp,int sockfd);
int main(int argc,char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;
	FILE *fp;
	if(argc!=2)
		err_quit("usage: ./tcpcli <IPadress>");
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		err_quit("socket error");
	bzero(&servaddr,sizeof(servaddr));	
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(9877);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	
	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
		err_quit("connect error");
	if((fp=fopen("data.txt","r+"))==NULL)
		err_quit("open file failed.");
	clistr(fp,sockfd);
	fclose(fp);
	exit(0);
}
void clistr(FILE *fp,int sockfd)
{
	size_t n;
	int maxfdp1;
	int stdeof=0;//标志stdin是否收到结束符
	fd_set rset;
	FD_ZERO(&rset);
	char buf[MAXLEN];
	for(;;)
	{
		if(stdeof==0)
			FD_SET(fileno(fp),&rset);
		FD_SET(sockfd,&rset);
		maxfdp1=max(fileno(fp),sockfd)+1;
		select(maxfdp1,&rset,NULL,NULL,NULL);
		if(FD_ISSET(sockfd,&rset))
		{
			if((n=read(sockfd,buf,MAXLEN))==0)
			{
				if(stdeof==1)
					return;
				else
					err_quit("str_cli:server teminated prematurely");
			}
			write(fileno(stdout),buf,n);
		}
		if(FD_ISSET(fileno(fp),&rset))
		{
			if((n=read(fileno(fp),buf,MAXLEN))==0)
			{
				stdeof=1;
				shutdown(sockfd,SHUT_WR);
				FD_CLR(fileno(fp),&rset);
				continue;
			}
			write(sockfd,buf,n);
		}
	}
}
void err_quit(const char *s)
{
	printf("%s\n",s);
	exit(0);
}
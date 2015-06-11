#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/select.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>

#include"my_unp.h"
#define MAXCLIENT 10
int main(int argc,char **argv)
{
	int client[MAXCLIENT],i,n,nready;//用来保存用户fdde数组
	fd_set rset,allset;//allset用于保存当前需要传入select的数据
	int maxfd;
	struct sockaddr_in servaddr,cliaddr;
	socklen_t clilen;
	int listenfd,connectfd,sockfd;//监听描述符和链接描述符
	
	char buf[MAXLEN];
	
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	if(listenfd<0)
		err_quit("socket error");
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORTNO);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	if(bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
		err_quit("bind error");
	listen(listenfd,1024);
	for(i=0;i<MAXCLIENT;i++)
		client[i]=1;
	FD_ZERO(&allset);
	FD_SET(listenfd,&allset);
	maxfd=listenfd;
	for(;;)
	{
		rset=allset;
		nready=select(maxfd+1,&rset,NULL,NULL,NULL);
		if(FD_ISSET(listenfd,&rset))//监听描述符表示有新连接
		{
			clilen=sizeof(cliaddr);
			if((connectfd=accept(listenfd,(struct sockaddr *)&cliaddr,&clilen))<=0)
				err_quit("accept error");
			for(i=0;i<MAXCLIENT;i++)
			{
				if(client[i]==-1)
				{
					client[i]=connectfd;
					break;
				}
			}
			if(i==MAXCLIENT)
				err_quit("too many client");
			FD_SET(connectfd,&allset);
			if(connectfd>maxfd)
				maxfd=connectfd;
			if(--nready==0)
				continue;
		}
		for(i=0;i<MAXCLIENT;i++)
		{
			if((sockfd=client[i])<0)
				continue;
			if(FD_ISSET(sockfd,&rset))
			{
				if((n=read(sockfd,buf,MAXLEN))==0)//连接符关闭
				{
					close(sockfd);
					FD_CLR(sockfd,&allset);
					client[i]=-1;
				}
				else
				{
					write(sockfd,buf,n);
				}
				if(--nready<=0)
					break;
			}
		}
	}
}
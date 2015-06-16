#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<sys/select.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

#include"my_unp.h"

void str_cli(FILE *fp,int sockfd);
int main(int argc,char **argv)
{
	struct sockaddr_in servaddr;
	int sockfd;
	
	if(argc!=2)
		err_quit("usage:./tcpcli_nonblock <IPaddress>");
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		err_quit("socket error");
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORTNO);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	
	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
		err_quit("connect error");
	str_cli(stdin,sockfd);
}

void str_cli(FILE *fp,int sockfd)
{
	char to[MAXLEN],fr[MAXLEN];
	char *tooptr,*toiptr,*froptr,*friptr;
	int maxfdp1,val,stdineof;
	ssize_t n,nwrite;
	fd_set rset,wset;
	
	val=fcntl(sockfd,F_GETFL,0);
	if(val<0)
		err_quit("fcntl getfl sockfd error");
	if(fcntl(sockfd,F_SETFL,val|O_NONBLOCK)<0)
		err_quit("fcntl setfl sockfd error");
	
	val=fcntl(STDIN_FILENO,F_GETFL,0);
	if(val<0)
		err_quit("fcntl getfl STDIN_FILENO error");
	if(fcntl(STDIN_FILENO,F_SETFL,val|O_NONBLOCK)<0)
		err_quit("fcntl setfl STDIN_FILENO error");
		
	val=fcntl(STDOUT_FILENO,F_GETFL,0);
	if(val<0)
		err_quit("fcntl getfl STDOUT_FILENO error");
	if(fcntl(STDOUT_FILENO,F_SETFL,val|O_NONBLOCK)<0)
		err_quit("fcntl setfl STDOUT_FILENO error");
	
	tooptr=toiptr=to;
	froptr=friptr=fr;
	stdineof=0;
	
	maxfdp1=max(max(STDIN_FILENO,STDOUT_FILENO),sockfd)+1;
	for(;;)
	{
		FD_ZERO(&rset);
		FD_ZERO(&wset);
		if(stdineof==0&&toiptr<&to[MAXLEN])
			FD_SET(STDIN_FILENO,&rset);
		if(friptr<&fr[MAXLEN])
			FD_SET(sockfd,&rset);
		if(tooptr!=toiptr)
			FD_SET(sockfd,&wset);
		if(froptr!=friptr)
			FD_SET(STDOUT_FILENO,&wset);
		if(select(maxfdp1,&rset,&wset,NULL,NULL)<0)
			err_quit("select error");
		if(FD_ISSET(STDIN_FILENO,&rset))
		{
			if((n=read(STDIN_FILENO,toiptr,&to[MAXLEN]-toiptr))<0)
			{
				if(errno!=EWOULDBLOCK)
					err_quit("read error on stdin");
			}
			else if(n==0)
			{
				stdineof=1;
				if(tooptr=toiptr)
					shutdown(sockfd,SHUT_WR);
			}
			else
			{
				toiptr+=n;
				FD_SET(sockfd,&wset);
			}
		}
		if(FD_ISSET(sockfd,&rset))
		{
			if((n=read(sockfd,friptr,&fr[MAXLEN]-friptr))<0)
			{
				if(errno!=EWOULDBLOCK)
					err_quit("read error on socket");
			}
			else if(n==0)
			{
				if(stdineof)
					return;
				else
					err_quit("str_cli:server terminated prematurely");
			}
			else
			{
				friptr+=n;
				FD_SET(STDOUT_FILENO,&wset);
			}
		}
		if(FD_ISSET(STDOUT_FILENO,&wset)&&((n=friptr-froptr)>0))
		{
			if((nwrite=write(STDOUT_FILENO,froptr,n))<0)
			{
				if(errno!=EWOULDBLOCK)
					err_quit("write error to stdout");
			}
			else
			{
				froptr+=nwrite;
				if(froptr==friptr)
					froptr=friptr=fr;
			}
		}
		if(FD_ISSET(sockfd,&wset)&&((n=toiptr-tooptr)>0))
		{
			if((nwrite=write(sockfd,tooptr,n))<0)
			{
				if(errno!=EWOULDBLOCK)
					err_quit("write error to socket");
			}
			else
			{
				tooptr+=nwrite;
				if(tooptr==toiptr)
				{
					tooptr=toiptr=to;
					if(stdineof)
						shutdown(sockfd,SHUT_WR);
				}
			}
		}
	}
	
}


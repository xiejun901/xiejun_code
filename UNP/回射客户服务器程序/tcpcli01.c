#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define MAXLEN 1024
void err_quit(const char *s);
void clistr(FILE *fp,int sockfd);
int main(int argc,char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;
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
	clistr(stdin,sockfd);
	exit(0);
}
void clistr(FILE *fp,int sockfd)
{
	size_t n;
	char send_buf[MAXLEN],recieve_buf[MAXLEN];
	while(fgets(send_buf,MAXLEN,fp)!=NULL)
	{
		write(sockfd,send_buf,strlen(send_buf));
		n=read(sockfd,recieve_buf,MAXLEN);
		recieve_buf[n]=0;
		fputs(recieve_buf,stdout);
	}
}
void err_quit(const char *s)
{
	printf("%s\n",s);
	exit(0);
}
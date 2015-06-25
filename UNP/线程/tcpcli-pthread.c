#include"my_unp.h"
#include<pthread.h>

void * sendToServer(void * argv);
int main(int argc,char ** argv)
{
	struct sockaddr_in servaddr;
	int sockfd;
	pthread_t tid;
	char buf[MAXLEN];
	ssize_t n;
	
	if(argc!=2)
		err_quit("usage:./tcpcli-pthread <ipaddress>");	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		err_quit("socket error");
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORTNO);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	
	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
		err_quit("connect error");
	pthread_create(&tid,NULL,sendToServer,(void *)&sockfd);
	while((n=read(sockfd,buf,MAXLEN))>0)
	{
		buf[n]=0;
		fputs(buf,stdout);	
	}
	close(sockfd);
	return 0;
}

void * sendToServer(void * argv)
{
	char buf[MAXLEN];
	int sockfd=*((int *)argv);
	while(fgets(buf,MAXLEN,stdin)!=NULL)
		write(sockfd,buf,strlen(buf));
	shutdown(sockfd,SHUT_WR);
	return NULL;
}

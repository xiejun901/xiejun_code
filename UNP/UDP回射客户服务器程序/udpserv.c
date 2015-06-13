#include"my_unp.h"
void dg_echo(int sockfd,struct sockaddr * pcliaddr,size_t clilen);
int main(int argc,char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr,cliaddr;
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORTNO);
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	if(bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
		err_quit("bind error");
	dg_echo(sockfd,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
}

void dg_echo(int sockfd,struct sockaddr * pcliaddr,size_t clilen)
{
	int n;
	socklen_t len;
	char msg[MAXLEN];
	for(;;)
	{
		len=clilen;
		n=recvfrom(sockfd,msg,MAXLEN,0,pcliaddr,&len);
		if(n<0)
			err_quit("recvfron error");
		if(sendto(sockfd,msg,n,0,pcliaddr,len)<0)
			err_quit("sendto error");
	}
}

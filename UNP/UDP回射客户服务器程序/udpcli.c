#include"my_unp.h"
void dg_cli(FILE *fp,int sockfd,struct sockaddr * pservaddr,size_t servlen);
int main(int argc,char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr;
	if(argc!=2)
		err_quit("usage:./udpcli <IPaddress>");
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
		err_quit("socket error");
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(PORTNO);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	
	dg_cli(stdin,sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	exit(0);
}

void dg_cli(FILE *fp,int sockfd,struct sockaddr * pservaddr,size_t servlen)
{
	int n;
	char sendline[MAXLEN],recvline[MAXLEN];
	while(fgets(sendline,MAXLEN,fp)!=NULL)
	{
		if(sendto(sockfd,sendline,strlen(sendline),0,pservaddr,servlen)<0)
			err_quit("sendto error");
		n=recvfrom(sockfd,recvline,MAXLEN,0,NULL,NULL);
		if(n<0)
			err_quit("recvfrom errror");
		recvline[n]=0;
		fputs(recvline,stdout);
	}
}

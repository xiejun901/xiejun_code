#ifndef _MY_UNP_H_
#define _MY_UNP_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORTNO 9877
#define MAXLEN 1024
void err_quit(const char *s);
#endif
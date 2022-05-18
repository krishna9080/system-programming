//program to create udp server
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#define ADDRSERV "127.0.0.1"
#define PORTNO 8013
#define MAX 1024
using namespace std;

int main(){
	struct sockaddr_in servaddr, cliaddr;
	char cmsg[MAX];
	char smsg[MAX]= "Hello from server to client";
	int  sockfd,slen,mlen;
	socklen_t clen;

	slen=sizeof(sockaddr_in);
	memset(&servaddr,0,slen);
	memset(&cliaddr,0, slen);
	memset(cmsg,0,MAX);

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORTNO);
	servaddr.sin_addr.s_addr = inet_addr(ADDRSERV);

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bind(sockfd, (struct sockaddr *)&servaddr,slen);
	listen(sockfd, 5);
	mlen = recvfrom(sockfd,cmsg,MAX,MSG_WAITALL,(struct sockaddr*)&cliaddr,&clen);
	cout<< cmsg << endl;
	mlen = sendto(sockfd,smsg,strlen(smsg),MSG_CONFIRM,(struct sockaddr*)&cliaddr,clen);
	cout << "Message sent from server" << endl;
	}	


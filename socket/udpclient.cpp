//program to create udp client
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
	struct sockaddr_in servaddr;
	char smsg[MAX];
	char cmsg[MAX] = "Hello from client to server";
	int mlen,slen, sockfd;
	socklen_t clen;
	slen = sizeof(sockaddr_in);
	memset(&servaddr,0, slen);
	memset(smsg,0,MAX);

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORTNO);
	servaddr.sin_addr.s_addr = inet_addr(ADDRSERV);

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	mlen=sendto(sockfd, cmsg, strlen(cmsg), MSG_CONFIRM,(struct sockaddr*)&servaddr,slen);
	cout<< "Message sent client to server" <<endl;
	mlen = recvfrom(sockfd,smsg,MAX,MSG_WAITALL,(struct sockaddr*)&servaddr,&clen);
	cout<< "received from  server :" << smsg << endl;
	}	


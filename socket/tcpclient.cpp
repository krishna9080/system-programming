#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define ADDRSERV "127.0.0.1"
#define PORTNO 8013
#define MAX 256
using namespace std;

int main()
{
        struct sockaddr_in servaddr;
       // char cmsg[MAX] = "Hello From Client to Server";
        char smsg[MAX];
	char cmsg[MAX];
        int sockfd,mlen,structlen;
        socklen_t servaddrlen;

        structlen = sizeof(sockaddr_in);
        memset(&servaddr,0,structlen);
        memset(smsg,0,MAX);


        servaddr.sin_family = AF_INET; //To use Internet Family of Addressing
        servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        servaddr.sin_port = htons(PORTNO);

        sockfd = socket(AF_INET,SOCK_STREAM,0);
        connect(sockfd,(struct sockaddr *) &servaddr,structlen);
	
	write(1,"Enter your Message for server: ",31);
	mlen=read(0,cmsg,MAX);
	mlen=write(sockfd,cmsg,strlen(cmsg));
	write(1,"Message sent from the client: ",31);
	write(1,cmsg,strlen(cmsg));
	mlen=read(sockfd,smsg,MAX);
	write(1,smsg,strlen(smsg));
	close(sockfd);

       // mlen=send(sockfd,cmsg,strlen(cmsg),0);
       // cout << mlen << "Message Sent from The Client to Server" << endl;
       // mlen=recv(sockfd,smsg,MAX,0);
       // cout << smsg << endl;
       // close(sockfd);
}

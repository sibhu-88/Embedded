//#purpose : TCP CLIENT
//#created Date :  30-05-2024
//#Coder : SIBHU
//#######--------START------########## 

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define pf printf

int main(int argc, char *argv[]) {


	if(argc != 3){
	 pf("Usage : ./srv PORT_NO IP_ADDR\n");
	 return 0;
	}

	int sockfd, newfd;
	char wrbuf[128],rdbuf[128];
	struct sockaddr_in srv;

	pf("Creating socket......\n");
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
	  perror("socket");
	  return 0;
	}
	pf("Socket created  Successfullyu......\n");

	srv.sin_family      = AF_INET;
	srv.sin_port        = htons(atoi(argv[1]));
	srv.sin_addr.s_addr = inet_addr(argv[2]);

	if(connect(sockfd, (struct sockaddr *)&srv, sizeof(srv))==0){
	pf("Connection establishment is success......\n");
	}
	else {
	 perror("connect");
	 return 0;
	}
	while(1){
		pf("Enter the string : ");
		scanf(" %[^\n]",wrbuf);
		write(sockfd, wrbuf, strlen(wrbuf)+1);
		bzero(rdbuf,128);
		read(sockfd, rdbuf, 128);
		pf("Received : %s\n",rdbuf);
	}
}

//#####---------END-------######### 

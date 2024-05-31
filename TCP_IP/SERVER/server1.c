//#purpose : TCP SERVER
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


	if(argc != 4){
	 pf("Usage : ./srv PORT_NO IP_ADDR no.of.connection...\n");
	 return 0;
	}

	int sockfd, newfd,rtn,cnt=0;
	char rdbuf[128];
	struct sockaddr_in srv,cln;

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

	if(bind(sockfd, (struct sockaddr *)&srv, sizeof(srv))==0){
	pf("Binding address is success......\n");
	}
	else {
	 perror("bind");
	 return 0;
	}

	if(listen(sockfd, atoi(argv[3]))==0){
	  pf("Server listening............\n");
	}
	else{
	  perror("listen");
	  return 0;
	}

	int len = sizeof(cln);
	pf("Server waiting for connection......\n");

	while(1){
		newfd=accept(sockfd, (struct sockaddr *)&cln, &len);

		if(newfd < 0){
			perror("accept");
			return 0;
		}
		sleep(1);
		pf("New Connection............\n");
		while(1){
			bzero(rdbuf, 128);
			rtn=read(newfd, rdbuf, 128);
			if(strncmp(rdbuf,"exit",4)==0){
			  cnt++;
			 if(cnt==atoi(argv[3])){
  			   pf("Connection breaked.......\n");
			   return 0;
			 }
			 pf("Connection breaked......\n");
			 break;
			}
			pf("Received string : %s\n", rdbuf);
		}
	}
}

//#####---------END-------######### 

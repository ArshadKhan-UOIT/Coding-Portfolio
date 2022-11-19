/********************************************************
 *
 *                          client.c
 *
 *******************************************************/
/*
*/
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "lib.h"

int main(int argc, char **argv) {
	struct addrinfo hints;
	struct addrinfo *addr;
	struct sockaddr_in *addrinfo;
	fd_set readfds;
	int rc;
	int sock;
	char buffer[512];
	char *ret;
	char *name = (char *) malloc((sizeof *name));
	if(argc != 2) {
		printf("Usage: client name\n");
		exit(1);
	}
	// the command line argument, which is the clients name is copied to name
	strcpy(name, argv[1]);
	// strncat(name, &colon, 1); 

	// printf("Client name: %s\n", name);

	/*
	 *  clear the hints structure to zero
	 */
	memset(&hints, 0, sizeof(hints));

	/*
	 *  want a stream on a compatible interface
    */
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_ADDRCONFIG;
	/*
	 *  localhost is the name of the current computer
	 */
	rc = getaddrinfo("localhost", NULL, &hints, &addr);
	if(rc != 0) {
		printf("Host name lookup failed: %s\n", gai_strerror(rc));
		exit(1);
	}

	/*
	 *  use the first result from getaddrinfo
	 */
	addrinfo = (struct sockaddr_in *) addr->ai_addr;

	sock = socket(addrinfo->sin_family, addr->ai_socktype, addr->ai_protocol);
	if(sock < 0) {
		printf("Can't create socket\n");
		exit(1);
	}

	/*
	 *  specify the port number
	 */
	addrinfo->sin_port = htons(55555);

	rc = connect(sock, (struct sockaddr *) addrinfo, addr->ai_addrlen);
	if(rc != 0) {
		printf("Can't connect to server\n");
		exit(1);
	}

	/*
	 *  free the results returned by get addrinfo
	 */
	freeaddrinfo(addr);


	// sending the clients name from the command line, which is stored in name 
	if (writeString(sock, name) < 0) {	// this is the first thing the server receives. its the clients name.
		printf("Error Writing Client Name\n");
		close(sock);
		exit(1);
	}
	free(name);	// after the name is sent i do not use it again so i freed it. 
	

	while(1) {
		FD_ZERO(&readfds);	//	clear the set 
		FD_SET(STDIN_FILENO, &readfds);	//	setting it to the standered input 
		FD_SET(sock, &readfds);	// setting it to the socket
		fflush(stdin);	// clearing it, really needed but good practice

		if (select(sock+1, &readfds, NULL, NULL, NULL) < 0) {	//	setting select to detect the readfds and checking for error 
			printf("Select failed in client\n");
			exit(1);
		}
		if (FD_ISSET(STDIN_FILENO, &readfds)) {	//	if the stdin is set 
			ret = fgets(buffer, 512, stdin);	//	get the stdin 
			if (ret == NULL) {	// if it returns a null
				shutdown(sock, SHUT_WR);
				free(ret);
				break;
			} else {	//	otherwise i write it
				if (writeString(sock, buffer) < 0 ) {	
					printf("Error Writing Client msg\n");
					close(sock);
					free(ret);
					exit(1);
				}
			}
		}
		//if the sock is set 
		if (FD_ISSET(sock, &readfds)) {
			ret = readString(sock);	//	 i need to read the string from the server
			if (ret == NULL) {	//	if theres nothing from the server then it probably disconnected 
				shutdown(sock, SHUT_WR);	//i shut down the socket 
				close(sock);	//	sock is closed
				free(ret); 
				exit(1);	
			} else {
				printf("%s", ret);	//	if it is not null then i print the return from the server 
			}
		}
	}
	free(ret);
	close(sock);

	exit(1);
}

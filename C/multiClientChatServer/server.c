/***********************************************
 *
 *                server.c
 *
 **********************************************/
/*
*/
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char **argv) {
	int sock, conn;
	int i, j;
	int rc;
	struct sockaddr address;
	socklen_t addrLength = sizeof(address);
	struct addrinfo hints;
	struct addrinfo *addr;
	char *message;
	char *newMessage = (char *) malloc((sizeof *newMessage));
	fd_set readfds, allfds;
	int client[FD_SETSIZE];
	int maxfd, maxi;
	int nready;
	
	/*
	 *  set the hints structure to zero
	 */
	memset(&hints, 0, sizeof(hints));

	/*
	 *  want a stream, also address that will accept all
	 *  connections on this host
	 */
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
	if((rc = getaddrinfo("localhost", "55555", &hints, &addr))) {
		printf("host name lookup failed: %s\n", gai_strerror(rc));
		exit(1);
	}

	/*
	 *  use the first entry returned by getaddrinfo
	 */
	sock = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
	if(sock < 0) {
		printf("Can't create socket\n");
		exit(1);
	}

	/*
	 *  want to be able to reuse the address right after
	 *  the socket is closed.  Otherwise must wait for 2 minutes
	 */
	i = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));

	rc = bind(sock, addr->ai_addr, addr->ai_addrlen);
	if(rc < 0) {
		printf("Can't bind socket\n");
		exit(1);
	}

	/*
	 *  free results returned by getaddrinfo
	 */
	freeaddrinfo(addr);

	rc = listen(sock, 5);
	if(rc < 0) {
		printf("Listen failed\n");
		exit(1);
	}

	/*
	 *  start with just the accept socket and no clients
	 */
	char* name[FD_SETSIZE];	//	this is for the clients name that is the first thing that is sent to the server from the client
	char* history[12];	// this is for the history
	// char* newHistory[12];
	char msgHistory[12][512];	// this is also for the history, ill explain more below why i needed 2 histories
	int k;
	int m;
	for (k=0;k<12;k++) {
		// history[i] = NULL;
		history[i] = (char *) malloc((sizeof *history));	// allocating the history with malloc
		history[i] = NULL;	//	making it null
		for (m=0;m<512;m++) {
			msgHistory[k][m] = 0;	//	also making this null
		}

	}
	int historyCounter = 0;	//	 this is the history counter
	maxfd = sock;
	maxi = -1;
	for(i=0; i<FD_SETSIZE; i++) {
		client[i] = -1;
		name[i] = NULL;		
	}
	FD_ZERO(&allfds);
	FD_SET(sock, &allfds);

	/*
	 * loop processing requests
	 */
	while(1) {
		readfds = allfds;
		/*
		 *  wait until something happens
		 */
		nready = select(maxfd+1, &readfds, NULL, NULL, NULL);
		/*
		 *  check to see if a client connection is waiting
		 */
		if(FD_ISSET(sock, &readfds)) {
			conn = accept(sock, (struct sockaddr*) &address, &addrLength);
			/*
			 * find an entry in the client table for it
			 */
			for(i=0; i<FD_SETSIZE; i++) {
				if(client[i] < 0) {
					client[i] = conn;
					name[i] = readString(conn);	//	this is how the server receives the clients name 
					strcat(name[i], ": ");  //	i then concatinate it so could have the colon and a space, so when i send the messages it will be like (ex. one: msg)
					int c;
					// printf("Client %s joined.\n", name[i]);
					for (c=0;c<12;c++) {	//when i get a clients name, then it is a new client and the history must be send. 
						if (history[c] != NULL) {
							// printf("History[%d]= %s",c, history[c]);

							if (writeString(conn, history[c]) < 0 ) {
								printf("Error Writing Client History\n");
								close(conn);
								exit(1);
							}
							
						}
					}
					break;
				}
			}
			FD_SET(conn, &allfds);
			if(conn > maxfd)
				maxfd = conn;
			if(i > maxi)
				maxi = i;
			if(--nready <= 0)
				continue;
		}
		/*
		 * now check all the existing clients
		 * to see if they have something to read
		 */
		for(i=0; i<=maxi; i++) {
			conn = client[i];
			if(conn < 0) {
				continue;
			}
			if(FD_ISSET(conn, &readfds)) {
				// printf("Client Name: %s\n", name[i]);
				message = readString(conn);
				if(message == NULL) {	// this means the client has disconnected, as the messsage is only null if the client ctrl+c's 
					printf("exiting because received null..\n");
					close(conn);
					client[i] = -1;
					FD_CLR(conn, &allfds);
				} 
				else {	// when the counter 12 then the array needs to be shifted 
					if (historyCounter == 12) { 
						historyCounter = 11;	//	each message after the history counter reaches 12, then the next message needs to be the last element
						int h, s;

						for(h=0;h<11;h++)
						{
							for (s=0;s<512;s++) {
								msgHistory[h][s] = msgHistory[h+1][s];
							}
						}
						for (s=0;s<512;s++) {
							msgHistory[11][s] = 0;
						}

						/*
						the reason why i had 2 histories is because i could not use strcpy on the char pointer array
						so just used a char 2d array then alloced the pointer one with the 2d array. and using the char 
						pointer array to send back to the client when a new client connect, was just easier than using the
						char 2d array  
						*/
						// for(b=0;b<11;b++)
						// {
						// 	history[b]=history[b+1];
						// }
						// history[11]=NULL;
					}
					strcpy(newMessage, name[i]);	//	i copy the clients name in the new message 
					strcat(newMessage, message);	// then i string concatinate the message with it so it could be sent 
					strcpy(msgHistory[historyCounter], newMessage);	//	i copy the new message into history
					history[historyCounter] = msgHistory[historyCounter];	//	then i allocate it to the history pointer 
					// printf("History[%d]= %s",historyCounter, history[historyCounter]);
					// printf("H2[%d]= %s",historyCounter, msgHistory[historyCounter]);
					historyCounter+=1;	// the history counter is incremened so i can keep control of the history index 
					for(j=0; j<=maxi; j++) {	//	the message is then sent to all of the clients but not the one who sent it 
						// if (j!=i) {		//	sent to all clients, but not the one who sent it
						conn = client[j];
						writeString(conn, newMessage);	//now sending to all clients since it was said in piazzia
						// }
					}
					free(message);	// 	i freeed the messsage 
				}
			}
		}
	}

	free(newMessage);	//	i freed the rest of the pointers that i used here 
	for (i=0;i<12;i++) {
		free(history[i]);	
	}
	free(history);
	for (i=0;i<FD_SETSIZE;i++) {
		free(name[i]);	
	}
	free(name);

	close(sock);
	exit(1);
}

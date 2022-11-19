/***********************************************
 *
 *                server.c
 *
 *  A more robust server that receives two
 *  integers from a client and returns their
 *  sum.  In return it gets a nice message
 *  from the client.
 **********************************************/

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

struct data {
	int arg1;
	int arg2;
	int result;
};

int receiveData(int conn, int *arg1, int *arg2);
int sendData(int conn, int result);

int main(int argc, char **argv) {
	int sock, conn;
	int i;
	int rc;
	struct sockaddr address;
	socklen_t addrLength = sizeof(address);
	struct addrinfo hints;
	struct addrinfo *addr;
	int len;
	// int arg1, arg2;
	int ret;
	char *message;

	struct data *numbers = (struct data*)malloc((sizeof *numbers));


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
	if((rc = getaddrinfo(NULL, "4321", &hints, &addr))) {
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
	 *  accept an arbitrary number of connections in a loop
	 */
	while((conn = accept(sock, (struct sockaddr*) &address, &addrLength))
		>= 0) {
		/*
		 *  read message from client and respond
		 */
		// ret = readn(conn, (char*) &numbers->arg1, sizeof(numbers->arg1));
		// if(ret != sizeof(numbers->arg1)) {
		// 	printf("Error reading arg1\n");
		// 	close(conn);
		// 	continue;
		// }
		// ret = readn(conn, (char*) &numbers->arg2, sizeof(numbers->arg2));
		// if(ret != sizeof(numbers->arg2)) {
		// 	printf("Error reading arg2\n");
		// 	close(conn);
		// 	continue;
		// }
		rc = receiveData(conn, &numbers->arg1, &numbers->arg2);
		if (rc == -1) {
			printf("Error receving data\n");
			close(conn);
			continue;
		}
		printf("Data from client: %d %d\n", numbers->arg1, numbers->arg2);
		numbers->result = numbers->arg1+numbers->arg2;
		rc = sendData(conn, numbers->result);
		if (rc == -1) {
			printf("Error sending data\n");
			close(conn);
			continue;
		}
		// ret = writen(conn, (char*) &numbers->result, sizeof(numbers->result));
		// if(ret != sizeof(numbers->result)) {
		// 	printf("Error sending result\n");
		// 	close(conn);
		// 	continue;
		// }

		message = readString(conn);
		if(message != NULL) {
			printf("Message from client: %s\n", message);
			free(message);
		} else {
			printf("Error receiving message from client\n");
		}
		close(conn);
	}

	close(sock);
	exit(0);
}

int receiveData(int conn, int *arg1, int *arg2) {
	int ret;
	int a1;
	int a2;
	ret = readn(conn, (char*) &a1, sizeof(a1));
	if(ret != sizeof(a1)) {
		printf("Error reading arg1\n");
		close(conn);
		// continue;
		return -1;
	}
	ret = readn(conn, (char*) &a2, sizeof(a2));
	if(ret != sizeof(a2)) {
		printf("Error reading arg2\n");
		close(conn);
		// continue;
		return -1;
	}
	*arg1 = a1;
	*arg2 = a2;
	return 0;
}

int sendData(int conn, int result) {
	int ret;
	ret = writen(conn, (char*) &result, sizeof(result));
	if(ret != sizeof(result)) {
		printf("Error sending result\n");
		close(conn);
		// continue;
		return -1;
	}
	return 0;
}

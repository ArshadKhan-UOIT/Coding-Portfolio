/********************************************************
 *
 *                          client.c
 *
 *  A more robust client example.  In this example the
 *  client has two arguments, integers.  These integers
 *  are sent to the server, which returns the sum of the
 *  two integers.
 *******************************************************/

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "lib.h"

struct data {
	int arg1;
	int arg2;
	int result;
};

int sendData(int sock, int arg1, int arg2);
int receiveData(int sock, int *result);

int main(int argc, char **argv) {
	struct addrinfo hints;
	struct addrinfo *addr;
	struct sockaddr_in *addrinfo;
	int rc;
	int sock;
	char buffer[512];
	int len;
	// int arg1, arg2;
	// int result;
	int ret;

	struct data *numbers = (struct data*)malloc((sizeof *numbers));
	

	if(argc != 3) {
		printf("Usage: client num1 num2\n");
		exit(1);
	}

	// arg1 = atoi(argv[1]);
	// arg2 = atoi(argv[2]);
	numbers->arg1 = atoi(argv[1]);
	numbers->arg2 = atoi(argv[2]);

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
	addrinfo->sin_port = htons(4321);

	rc = connect(sock, (struct sockaddr *) addrinfo, addr->ai_addrlen);
	if(rc != 0) {
		printf("Can't connect to server\n");
		exit(1);
	}

	/*
	 *  free the results returned by get addrinfo
	 */
	freeaddrinfo(addr);

	/*
	 *  send a message to the server and echo the response
	 */
	
	// ret = writen(sock, (char*) &arg1, sizeof(arg1));
	// if(ret != sizeof(arg1)) {
	// 	printf("Error sending first argument\n");
	// 	close(sock);
	// 	exit(1);
	// }
	// ret = writen(sock, (char*) &arg2, sizeof(arg2));
	// if(ret != sizeof(arg2)) {
	// 	printf("Error sending second argument\n");
	// 	close(sock);
	// 	exit(1);
	// }
	rc = sendData(sock, numbers->arg1, numbers->arg2);
	if (rc == -1 ) {
		printf("Error sending data\n");
		close(sock);
		exit(1);
	}

	rc = receiveData(sock, &numbers->result);
	if (rc == -1 ) {
		printf("Error receving data\n");
		close(sock);
		exit(1);
	}

	// ret = readn(sock, (char*) &result, sizeof(result));
	// if(ret != sizeof(result)) {
	// 	printf("Error reading result\n");
	// 	close(sock);
	// 	exit(1);
	// }
	printf("The sum of %d and %d is %d\n", numbers->arg1, numbers->arg2, numbers->result);
	ret = writeString(sock, "Thank You");
	if(ret) {
		printf("Error sending thank you\n");
		close(sock);
		exit(1);
	}

	close(sock);

	exit(0);
}

int sendData(int sock, int arg1, int arg2) {
	int ret;
	ret = writen(sock, (char*) &arg1, sizeof(arg1));
	if(ret != sizeof(arg1)) {
		printf("Error sending first argument\n");
		close(sock);
		// exit(1);
		return -1;
	}
	ret = writen(sock, (char*) &arg2, sizeof(arg2));
	if(ret != sizeof(arg2)) {
		printf("Error sending second argument\n");
		close(sock);
		// exit(1);
		return -1;
	}
	return 0;
}

int receiveData(int sock, int *result) {
	int ret;
	int res;
	ret = readn(sock, (char*) &res, sizeof(res));
	if(ret != sizeof(res)) {
		printf("Error reading result\n");
		close(sock);
		// exit(1);
		return -1;
	}
	*result = res;
	return 0;
}
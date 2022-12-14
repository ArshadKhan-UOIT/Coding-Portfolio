/*********************************************
 *
 *                 list.c
 *	the first argunent is host name and the second 
	is service name. 
	Eg. ./list www.google.com http
	The host & service name is then inputting into 
	the getaddrinfo() procedure, this allows us to 
	retrieve the IP addresses and port info from the 
	specified input
	 
 *  Walk the result returned by getaddrinfo
 *  and print the information that we find.
 ********************************************/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
	char *host;
	char *service;
	struct addrinfo hints;
	struct addrinfo *addr;
	struct addrinfo *save;
	struct sockaddr_in *addrinfo;
	int rc;
	char address[512];

	/*
	 *  check for proper usage
	 */
	if(argc != 3) {
		printf("Usage: list hostname service\n");
		exit(1);
	}

	host = argv[1];
	service = argv[2];

	/*
	 *  request all protocol families
	 */
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;

	rc = getaddrinfo(host, service, &hints, &addr);
	if(rc != 0) {
		printf("getaddrinfo failed: %s\n", gai_strerror(rc));
		exit(1);
	}

	/*
	 *  save the result so we can free it later
	 */
	

	while(addr != NULL) {
		if(addr->ai_family == AF_INET)
			printf("IPv4 ");
		else if(addr->ai_family == AF_INET6)
			printf("IPv6 ");
		else 
			printf("Unknown family ");

		if(addr->ai_socktype == SOCK_STREAM)
			printf("stream ");
		else if(addr->ai_socktype == SOCK_DGRAM)
			printf("datagram ");
		else
			printf("unknown socket type ");

		addrinfo = (struct sockaddr_in *) addr->ai_addr;
		printf("port: %d ", ntohs(addrinfo->sin_port));
		/*
		 *  convert the IP address to human readable form
		 */
		inet_ntop(addr->ai_family, (void*) &addrinfo->sin_addr, 
			address, sizeof(address));
		printf("address: %s ",address);
		printf("\n");
		addr = addr->ai_next;
	}

	freeaddrinfo(save);

	exit(0);
}

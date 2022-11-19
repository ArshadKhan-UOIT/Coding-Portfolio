/******************************************
 *
 *              copy.c
 *
 * Redirects user standered input 
 * to standered output 
 *   
 *
 *****************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int fin;
	int fout;
	int n;
	char buffer[512];
	int ret;
	
	fin = STDIN_FILENO;
	
	fout = STDOUT_FILENO;
	

	n=1;  // Get the process started
	while(n > 0) {
		n = read(fin, buffer, 512);
		if(n < 0) {
			printf("Error on read: %s\n",strerror(errno));
			exit(1);
		}
		ret = write(fout, buffer, n);
		if(ret < 0) {
			printf("Erroc on write: %s\n",strerror(errno));
			exit(1);
		}
	}
	close(fin);
	close(fout);
	exit(0);
}

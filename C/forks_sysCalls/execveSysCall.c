/******************************************
 *
 *               execveSysCall
 *
 *  This program illustrates the use of the
 *  execve system call.
 *
 *****************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

extern char **environ;

int main(int argc, char **argv) {
	int pid;
	int ret;
	int status;

	if((pid = fork())) {
		if(pid < 0) {
			printf("Fork error: %s\n",strerror(errno));
			exit(1);
		}
		printf("Wait: %d\n", wait(&status));
	} else {
		ret = execve("forks", argv, environ);
		if(ret < 0) {
			printf("Execve failed: %s\n", strerror(errno));
			exit(1);
		}
	}

	exit(0);
}

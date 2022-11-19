/******************************************
 *
 *               stdInput.c
 * 
 * This program takes a file and uses it  
 * as user standered input. 
 * Then uses the program copy.c 
 * to redirect users 
 * standered input to standered output and
 * then stdInput.c uses copy.c standered output 
 * and writes it to a specified output file
 *  
 * This program illustrates the use of the
 *  execve system call.
 *  
 * 
 *****************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;

int main(int argc, char **argv) {
	int pid;
	int ret;
	int status;
    int fin = open(argv[1], O_RDONLY);

	if(argc != 3) {
		printf("Usage: stdInput <original file> <copy file>\n");
		exit(1);
	}

    if(fin < 0) {
		printf("Can't open input file: %s\n",strerror(errno));
		exit(1);
	}
    dup2(fin, STDIN_FILENO);
    close(fin);

    int fout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fout < 0) {
		printf("Can't open output file: %s\n",strerror(errno));
		exit(1);
	}
    dup2(fout, STDOUT_FILENO);
    close(fout);

	if((pid = fork())) {
		if(pid < 0) {
			printf("Fork error: %s\n",strerror(errno));
			exit(1);
		}
        wait(&status);
	} else {

		ret = execve("copy", argv, environ);
		if(ret < 0) {
			printf("Execve failed: %s\n", strerror(errno));
			exit(1);
		}
	}

	exit(0);
}

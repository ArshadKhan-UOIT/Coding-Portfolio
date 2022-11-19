/******************************************
 *
 *              filePermiss.c
 *
 *  A simple copy program that demostrates
 *  basis system calls.
 *
 *  Usage: filePermiss infile outfile
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


void file_permissions(const char *_file, struct stat fileStat) {
	printf("File Permissions for: %s\n",_file);
	//directory, owner, group, other (public) 
	// r (read), w (write), x (execute)
	// '-' (not)
	printf("File Permissions: ");
	//directory
	printf((S_ISDIR(fileStat.st_mode)) ? "d":"-");
	//owner
	printf(fileStat.st_mode & S_IRUSR ? "r":"-");
	printf(fileStat.st_mode & S_IWUSR ? "w":"-");
	printf(fileStat.st_mode & S_IXUSR ? "x":"-");	
	//group
	printf(fileStat.st_mode & S_IRGRP ? "r":"-");
	printf(fileStat.st_mode & S_IWGRP ? "w":"-");
	printf(fileStat.st_mode & S_IXGRP ? "x":"-");
	//other (public)
	printf(fileStat.st_mode & S_IROTH ? "r":"-");
	printf(fileStat.st_mode & S_IWOTH ? "w":"-");
	printf(fileStat.st_mode & S_IXOTH ? "x":"-");
	printf("\t%o",(unsigned int) fileStat.st_mode);
	printf("\n\n");
}

int main(int argc, char **argv) {
	int fin;
	int fout;
	int n;
	char buffer[512];
	int ret;
	struct stat fileStat;

	if(argc != 3) {
		printf("Usage: lab1 infile outfile\n");
		exit(1);
	}

	fin = open(argv[1], O_RDONLY);
	if(fin < 0) {
		printf("Can't open input file: %s\n",strerror(errno));
		exit(1);
	}
	fstat(fin,&fileStat);
	file_permissions(argv[1], fileStat);

	// fout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//changed it from when the file was created
	fout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, fileStat.st_mode);	
	if(fout < 0) {
		printf("Can't open output file: %s\n",strerror(errno));
		exit(1);
	}

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
	// chmod(argv[2], fileStat.st_mode);	//changing to input file permissions
	file_permissions(argv[2], fileStat);

	close(fin);
	close(fout);
	exit(0);
}

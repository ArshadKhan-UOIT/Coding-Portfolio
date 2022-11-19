CFLAGS = -Wall -g

.PHONY : all clean

all: forks execveSysCall

forks : forks.o
	cc -o forks forks.o

execveSysCall : execveSysCall.o
	cc -o execveSysCall execveSysCall.o

clean:
	rm forks forks.o execveSysCall execveSysCall.o

CFLAGS = -Wall -g

.PHONY : all clean

all: dirList

dirList : dirList.o
	cc -o dirList dirList.o

clean:
	rm dirList dirList.o

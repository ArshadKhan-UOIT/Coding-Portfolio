CFLAGS = -Wall -g

.PHONY : all clean

all: copy stdInput

copy : copy.o
	cc -o copy copy.o

stdInput : stdInput.o
	cc -o stdInput stdInput.o

clean:
	rm copy copy.o stdInput stdInput.o

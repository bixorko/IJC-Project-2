CC=gcc
CPP=g++
CFLAGS=-std=c99 -pedantic -Wall
CPFLAGS=-std=c++11 -pedantic -Wall

all: tail tail2

tail: tail.o
	$(CC) $(CFLAGS) -o tail tail.o

tail2: tail2.o
	$(CPP) $(CPFLAGS) -o tail2 tail2.o

tail.o: tail.c
	$(CC) $(CFLAGS) -c tail.c

tail2.o: tail2.cc
	$(CPP) $(CPFLAGS) -c tail2.cc

clean:
	rm -f tail tail2 *.o
	clear

run : 
	make
	valgrind ./tail2 -n -3 textfile
	valgrind ./tail2 -n -3 <textfile
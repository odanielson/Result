CC = gcc
CFLAGS = -Wall -std=c99 -O2

all: test

test: test.c
	$(CC) test.c -o test

clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf *~

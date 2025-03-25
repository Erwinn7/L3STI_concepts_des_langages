CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

util_rand.o: util_rand.c util_rand.h
	$(CC) $(CFLAGS) -c util_rand.c

main: main.c util_rand.o
	$(CC) $(CFLAGS) main.c util_rand.o -o main

clean:
	rm -f *.o main

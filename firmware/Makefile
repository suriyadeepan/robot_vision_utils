#!/bin/sh
main: main.o athena.o
	$(CC) -o main main.o athena.o

main.o: main.c athena.h
	$(CC) $(CFLAGS) -g -c  main.c

athena.o: athena.c athena.h
	$(CC) $(CFLAGS) -g -c athena.c

clean:	
	rm *.[oa] main

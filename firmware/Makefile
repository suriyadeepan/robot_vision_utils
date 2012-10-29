#!/bin/sh
main: main.o athena.o
	gcc -o main main.o athena.o

main.o: main.c athena.h
	gcc $(CFLAGS) -g -c  main.c

athena.o: athena.c athena.h
	gcc $(CFLAGS) -g -c athena.c

clean:	
	rm *.[oa] main

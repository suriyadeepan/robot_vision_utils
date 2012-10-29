#!/bin/sh
<<<<<<< HEAD
main:
	gcc -o main main.c

clean:	
	rm *.[oa]
=======
main: main.o athena.o
	gcc -o main main.o athena.o

main.o: main.c athena.h
	gcc $(CFLAGS) -g -c  main.c

athena.o: athena.c athena.h
	gcc $(CFLAGS) -g -c athena.c

clean:	
	rm *.[oa] main
>>>>>>> 4ca006d78148e4739b4519c50cd815a39315fe39

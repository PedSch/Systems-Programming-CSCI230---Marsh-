/* pedro schmidt
hw6
csci230
10-10:50 mwf
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

# -*- MakeFile -*-
all: hw6-pedroschmidt

hw6-pedroschmidt: hw6-pedroschmidt.o hw6-A-pedroschmidt.o hw6-B-pedroschmidt.o hw6-C-pedroschmidt.o hw6-D-pedroschmidt.o
	gcc -o hw6-pedroschmidt hw6-pedroschmidt.o hw6-A-pedroschmidt.o hw6-B-pedroschmidt.o hw6-C-pedroschmidt.o hw6-D-pedroschmidt.o

hw6-pedroschmidt.o: hw6-pedroschmidt.c
	gcc -c hw6-pedroschmidt.c

hw6-A-pedroschmidt.o: hw6-A-pedroschmidt.c hw6-A-pedroschmidt.h
	gcc -c hw6-A-pedroschmidt.c

hw6-B-pedroschmidt.o: hw6-B-pedroschmidt.c hw6-B-pedroschmidt.h
	gcc -c hw6-B-pedroschmidt.c

hw6-C-pedroschmidt.o: hw6-C-pedroschmidt.c hw6-C-pedroschmidt.h
	gcc  -c hw6-C-pedroschmidt.c

hw6-D-pedroschmidt.o: hw6-D-pedroschmidt.c hw6-D-pedroschmidt.h
	gcc -c hw6-D-pedroschmidt.c

clean:
	rm -f hw6-pedroschmidt*.o



# Makefile per es5_dealloca_albero.c

CFLAGS=-ansi -Wpedantic -Wall -D_POSIX_SOURCE=1 -D_POSIX_C_SOURCE=200112L
LIBRARIES=

all: 	es5_dealloca_albero.exe

es5_dealloca_albero.exe: es5_dealloca_albero.o
	gcc -o es5_dealloca_albero.exe ${CFLAGS} es5_dealloca_albero.o ${LIBRARIES}

es5_dealloca_albero.o: es5_dealloca_albero.c
	gcc -c ${CFLAGS} es5_dealloca_albero.c 

.PHONY:	clean

clean:
	rm -f es5_dealloca_albero.o es5_dealloca_albero.exe


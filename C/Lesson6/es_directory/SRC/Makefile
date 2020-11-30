CFLAGS= -ansi -Wpedantic -Wall -Werror

#include directory containing headers
INCLUDEDIR=../INCLUDE

#LIBRARIES
LIBRARIES=-lm


all:		main.exe

main.exe:	main.o quadrato.o dimezza.o
		gcc ${CFLAGS} -o main.exe main.o quadrato.o dimezza.o ${LIBRARIES}

#main.o depends on main.c quadrato.h and dimezza.h, file headers are in another folder so
#we have to call them in a different way
main.o:		main.c	${INCLUDEDIR}/quadrato.h ${INCLUDEDIR}/dimezza.h
		gcc -c ${CFLAGS} -I${INCLUDEDIR} main.c

quadrato.o:	quadrato.c
		gcc -c ${CFLAGS} quadrato.c

dimezza.o:	dimezza.c
		gcc -c ${CFLAGS} dimezza.c

.PHONY:		clean

clean:		
		rm -f main.exe main.o quadrato.o dimezza.o *~ core


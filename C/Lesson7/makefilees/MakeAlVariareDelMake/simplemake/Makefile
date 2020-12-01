CFLAGS=-ansi -Wpedantic -Wall -Werror

all:		main.exe

main.exe:	main.o  funzioni.o
		gcc ${CFLAGS} -o main.exe main.o funzioni.o

main.o:		main.c  funzioni.h strutture.h Makefile
		gcc -c ${CFLAGS} main.c

funzioni.o:	funzioni.c  strutture.h Makefile
		gcc -c ${CFLAGS} funzioni.c

clean:		
		-rm main.exe *.o


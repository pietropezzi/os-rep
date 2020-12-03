CFLAGS=-ansi -Wpedantic -Werror -Wall -D_THREAD_SAFE -D_REENTRANT -D_POSIX_SOURCE=200112L
LFLAGS=-lpthread


all:			main.exe

main.exe:		main.o
			-gcc ${CFLAGS} -o main.exe main.o ${LFLAGS}

main.o:			main.c
			-gcc ${CFLAGS} -c main.c

.PHONY:			clean

clean:			
			rm -f main.exe main.o

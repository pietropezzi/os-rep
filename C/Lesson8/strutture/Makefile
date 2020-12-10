CFLAGS=-ansi -Wpedantic -Wall -Werror -D_POSIX_C_SOURCE=200112L -D_THREAD_SAFE -D_REENTRANT
LIBRARIES=-lpthread


all:			strutt.exe


strutt.exe:		strutt.o
			gcc ${CFLAGS} -o strutt.exe strutt.o ${LIBRARIES}

strutt.o:		strutt.c
			gcc ${CFLAGS} -c strutt.c

.PHONY:			clean
			
clean:			
			rm -f strutt.exe strutt.o

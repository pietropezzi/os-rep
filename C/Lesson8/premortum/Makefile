CFLAGS=-ansi -Wpedantic -Werror -Wall -D_POSIX_SOURCE=200112L -D_REENTRANT -D_THREAD_SAFE
LIBRARIES=-lpthread

all:			main.exe

main.exe:		main.o
			gcc ${CLFLAGS} -o main.exe main.o ${LIBRARIES}

main.c:			main.c
			gcc ${CFLAGS} -c main.c

.PHONY:			clean
		

clean:			
			rm -f main.o main.exe

CFLAGS=-ansi -Wpedantic -Werror -Wall

all:			main.exe

main.exe:		main.o variabiliglobali.o
			gcc ${CFLAGS} -o main.exe main.o variabiliglobali.o 

main.o:			main.c variabiliglobali.h define.h
			gcc ${CFLAGS} -c main.c 

variabiliglobali.o:	variabiliglobali.c 
			gcc ${CFLAGS} -c variabiliglobali.c

variabiliglobali.c:	define.h
			./creaC.sh

variabiliglobali.h:	define.h
			./creaH.sh

.PHONY:			clean cleanall

clean:			
			rm -f main.exe main.o variabiliglobali.o *~ core

cleanall:		
			rm -f main.exe main.o variabiliglobali.o variabiliglobali.c variabiliglobali.h *~ core

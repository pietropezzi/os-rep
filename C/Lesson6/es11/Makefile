CFLAGS= -ansi -Wpedantic -Werror -Wall -D_POSIX_SOURCE

all:					dammi_il_prec.exe
	
dammi_il_prec.exe:			dammi_il_prec.o
			gcc ${CFLAGS} -o dammi_il_prec.exe dammi_il_prec.o ${LIBRARIES}

dammi_il_prec.o:			dammi_il_prec.c
			gcc ${CFLAGS} -c dammi_il_prec.c ${LIBRARIES}

.PHONY:					clean

clean:				
			rm -f dammi_il_prec.exe dammi_il_prec.o 

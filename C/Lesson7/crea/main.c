#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "variabiliglobali.h"
#include "define.h"

int main(void){	
	printf("Value of NUM: %d\n",NUM);
	printf("Value calculated by conta(): %d\n",conta());
	printf("Value of var1: %d\n",var1);	
	return(0);
}

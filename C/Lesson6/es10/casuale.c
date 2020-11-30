#ifndef __POSIX_SOURCE
#define __POSIX_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*to generate the random number we include time.h*/
#include <time.h>

int main(void){
	srand(time(NULL));
	while(1){
		if( (rand()%10) == 3 ){
			break;
		}
	}	
	return(0);
}

#ifndef __POSIX_SOURCE
#define __POSIX_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

unsigned int dammi_il_precedente(unsigned int n){
	static unsigned int prev=0;
	unsigned int curr;
	printf("Previous: %d Current: %d\n",prev,n);
	curr=prev;
	prev=n;
	return(curr);
}

int main(void){
	srand(time(NULL));
	while(1){
		if((dammi_il_precedente(rand())%10) == 3){
			break;
		}
	}
	return(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "macro.h"

int main(void){
	int32_t *p;
	int check=0,j=0,i=0;
	ALLOCAVETTORE(p);
	for(i=-1000;i<=-991;i++){
		if(p[j]==i){
			check++;
		}
		j++;
	}

	if(check==10){
		printf("the macro added the correct values!\n");
	}
		
	for(i=0;i<10;i++)
		p[i]=-19+i;

	for(i=0;i<10;i++){
		printf("%d ,",p[i]);
		fflush(stdout);
	}
	printf("\n");
	 
	return(0);
}

#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>	/* intptr_t */
#include <inttypes.h> /* PRIdPTR */

#define NUM_THREAD 10

void *func(void *args){
	intptr_t index;
	index=((intptr_t)args);
	
	/* in questo caso non devo fare la free di args */
	printf("Il thread ha otternuto %" PRIiPTR "\n",index);
	
	pthread_exit(NULL);
	
}

int main(){
	pthread_t tid;
	int rc;
	intptr_t t;
	
	for(t=0; t<NUM_THREAD; t++){
		rc = pthread_create(&tid, NULL, func, (void*)t);
		if (rc) {
			printf("pthread_create failed.\n");
			exit(1);
		}
	}
			
	pthread_exit(NULL);
}

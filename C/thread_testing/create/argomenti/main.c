#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREAD 10

void *func(void *args){
	int index;
	index = *((int*)args);
	
	free(args);
	
	printf("Il thread ha ricevuto %i\n", index);
	pthread_exit(NULL);
	
}

int main(){
	pthread_t t;
	/* i is used in the for cicle and rc stands for
	 * return code
	 */ 
	int i, rc;
	/* this int pointer will be sent as argument to
	 * the thread
	 */
	int *p;

	for (i=0; i<NUM_THREAD; i++){
		/* i have to allocate the pointer each time */
		p=(int*)malloc(sizeof(int));
		*p = i;
		rc = pthread_create(&t, NULL, func, (void*)p); 
		if (rc) {
			printf("pthread_create failed, code error: %d",rc);
			exit(1);
		}
	}

	printf("i end of main value %d\n",i);	
	pthread_exit(NULL);
}

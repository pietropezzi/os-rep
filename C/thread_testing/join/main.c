#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREAD 10


void *func(void *args){
	int *ptr;
	int index;
	
	index= *((int*)args);
	free(args);
	
	ptr=(int*) malloc(sizeof(int));
	
	*ptr=100+index;
	/*returns ptr which is index+100 */
	pthread_exit((void*)ptr);
	

}


int main(){
	/* creo un array di threadid */
	pthread_t tid[NUM_THREAD];
	int i, rc;
	int *p;
	
	for(i=0; i<NUM_THREAD; i++){
		p=(int*)malloc(sizeof(int));
		*p=i;
		rc = pthread_create(&tid[i], NULL, func, (void*)p);
		if (rc) {
			printf("pthread_create failed.");
			exit(1);
		}
	}
	
	for(i=0; i<NUM_THREAD; i++){
		int ris;
		
		rc = pthread_join(tid[i], (void**)&p);
		ris = *p;
		printf(" il pthread %d restituisce %i\n",i,ris);
		free(p);
	}
	
	return(0);
}

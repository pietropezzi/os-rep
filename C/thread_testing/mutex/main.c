#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <inttypes.h>

#define NUM_THREAD 10
pthread_t tid[NUM_THREAD];
/* mutex var */
pthread_mutex_t mutexdata;
int data=14;

void *func(void *args){
	pthread_mutex_lock(&mutexdata);
	
	if (data>0){
		data--;
	}
	
	pthread_mutex_unlock(&mutexdata);
	
	pthread_exit(NULL);
}


int main(){
	int rc, i;
	int *p;
	
	pthread_mutex_init(&mutexdata,NULL);
	
	for(i=0;i<NUM_THREAD;i++){
		rc = pthread_create(&tid[i], NULL, func, NULL);
		if (rc) {
			printf("pthread_create failed.\n");
			exit(1);
		}
	}
	
	for(i=0;i<NUM_THREAD;i++){
		rc = pthread_join(tid[i], (void**)&p);
		if (rc) {
			printf("pthread_join failed.\n");
			exit(1);
		}
	}
	
	printf("data : %d\n",data);
	
	pthread_mutex_destroy(&mutexdata);
	
	pthread_exit(NULL);
}

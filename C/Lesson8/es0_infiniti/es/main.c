#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#ifndef _REENTRANT
#define _REENTRANT
#endif

#ifndef _POSIX_C_SOURCE
#if _POSIX_C_SOURCE < 200112L
#undef  _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif
#else
#define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
/*
 * including this librarie lets us use PRIuPTR
 * wich is a decimal formato for uintptr_t, this is useful since uintptr_t can change 
 * cross platforms but PRIuPTR saves our ass.
 */ 
#include <inttypes.h>

void *PrintIndex(void *arg){
	printf("Thread Index = %" PRIuPTR ".\n", (uintptr_t)arg );
	pthread_exit(NULL);
}



int main(void){
	pthread_t thread_id;
	int thread_return_value;
	uintptr_t t;

	for(t=0;;t++){
		printf("Creating thread n %" PRIuPTR "... \n" ,t);
		thread_return_value = pthread_create ( &thread_id,NULL,PrintIndex, (void *)t);
		if (thread_return_value){
			char msg[100];
			/*STRERROR_R is very useful in this situation,
			 * we can give it the retunred value from out failed pthread_create
			 * and this function gives us back , in this case , a message in our String msg
			 * so we dont have to check what type of error it is we just can print the msg!"
			 */
			strerror_r(thread_return_value,msg,100);
			printf("ERROR! pthread_create failed : %s\n", msg);
			exit(1);
		}
	}

	pthread_exit(NULL);
	return(0);
	
}

#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#ifndef _REENTRANT
#define _REENTRANT
#endif

#ifdef  _POSIX_C_SOURCE
#if     _POSIX_C_SOURCE < 200112L
#undef  _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif
#else
#define _POSIX_C_SOURCE 200112L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
 * check for thread_create error msg
 */
#include <errno.h>

/*
 * this gives us uintptr_t
 */
#include <stdint.h>

/*
 *  PRIiPTR
 */
#include <inttypes.h>

/*
 * create a string to store the
 * message to store the erro message
 * given by strerror_r
 */ 
#include <string.h>
/*
 * This gives us pthread_create, pthread_join
 * and pthread_t 
 */
#include <pthread.h>

#define N_THREADS 1000
#define MSG_LEN 100

void *t_Action(void *args){
	printf("Index %" PRIiPTR ".\n", (uintptr_t)args);
	pthread_exit(NULL);
}

int main(void){
	/*
	 * i guess this is an array of threads so that
	 * when we call pthread_join we dont have to look
	 * for their id and can just use this array for joining them
	 * all together
	 */
	pthread_t threads[N_THREADS];
	int ERR_cod, t, *p;
	uintptr_t t0=0;

	while (1){
		/*
		 * Creating 1000 threads
		 */
		for(t=0;t<N_THREADS;t++,t0++){
			printf("Creating thread n %" PRIiPTR ".\n", t0);
			ERR_cod = pthread_create ( &threads[t],NULL,t_Action, (void *)t0 );
			if (ERR_cod) {
				char msg[MSG_LEN];
				strerror_r(ERR_cod,msg,MSG_LEN);
				printf("ERROR! pthread_create failed: %s\n",msg);
				exit(1);
			}
		}
		/*
		 * Join all 1000 threads 
		 */
		printf("------------ JOIN ------------\n");
		for(t=0;t<N_THREADS;t++){
			ERR_cod = pthread_join( threads[t], (void**)&p );
			if (ERR_cod){
				char msg[MSG_LEN];
				strerror_r(ERR_cod,msg,MSG_LEN);
				printf("ERROR! pthread_join failed: %s\n",msg);
				exit(1);
			}
		}	
	}

	printf("End of main.\n");
	fflush(stdout);

	pthread_exit(NULL);
	return(0);
}

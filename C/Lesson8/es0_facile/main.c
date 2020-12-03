#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N_THREADS 10

/*this function is what a thread does when it is created*/
void *thread_action(void *p){
	/*sleep for 5 secs*/
	sleep(5);
	/*prints the random number given*/
	printf("%f\n",*((double*)p));
	/*frees the pointer p*/
	free(p);
	/*end the current thread*/
	pthread_exit(NULL);
}


int main(void){
	pthread_t th;
	int rc, t;
	double *p;
	
	srand( time(NULL));
	for(t=0;t<N_THREADS;t++){
		/*allocates for pointer double*/
		p=malloc(sizeof(double));
		/*checks if error in malloc*/
		if(p==NULL){
			perror("Malloc failed!");
			pthread_exit(NULL);
		}
		/*creates a random double number*/
		*p=(double)(rand()%100000);
		printf("Creating thread n*%d ...\n",t);
		/*
		 * here it creates a thread and also uses rc to get
		 * the int return from the pthread_create, we can use rc
		 * to check if there was an error
		 */
	        rc = pthread_create(& th, NULL, thread_action, p);
		/*checks for error in pthread_create*/
		if (rc){
			printf("ERROR; return code from pthread_create() is %d\"n",rc);
			exit(-1);
		}	
	}
	/*prints rc and end of main*/
	printf("return  of pthread_create is : %d\n",rc);
	printf("End of main\n");
	fflush(stdout);

	/*closes the main thread and waits for all the other threads to end*/
	pthread_exit(NULL);
	/*then ends the process*/
	return(0);
}


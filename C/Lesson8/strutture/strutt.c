/*
 * Since we already added _THREAD_SAFE _REENTRANT and _POSIX_C_SOURCE... to
 * the Makefile CFLAGS we dont neet to include them in this code!
 * This means that all previous codes added these define without any reason 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
/*
 * Since in this exercise we need to send a 100 chars String to
 * each thread we will use "string.h" librarie.
 */
#include <string.h>

/*
 * Number of threads we need to create at
 * the start of the programm
 */
#define NUM_THREADS 4

/*
 * We create this struct which will hold all
 * the arguments that we will send to the
 * "Action" function when creating a thread
 * ("TArgs" stands for Thread's arguments!)
 */
typedef struct TArgs{
	/*
	 * N is how many threads the thread has to create
	 * Str is a String
	 * and Index is a number between 0 and N-1
	 */
	int N;
	char Str[100];
	int Index;
}targs;

/*
 * Funct that holds all the threads actions
 * gets a pointer in input so that we can
 * send arguments using the struct pointer.
 * ("TAction" stands for threads action)
 */
void *TAction(void *ptr){
	/*creates 2 new targs structs*/
	targs *p, *p1;
	/*creates new counter and return code since i will have to
	create new threads*/
	int i;
	int rc;

	/*p is just a copy of the given args
	creates a copy of the given pointer so that
	it doesnt ruin the given arguments and just
	works on the copies*/
	p = (targs*)ptr;

	printf("Start of thread n(%i) Index(%i) \n", p->N, p->Index);
	fflush(stdout);
	/*sleeps for 1 sec*/ 
	sleep(1);

	if( p->N > 1 ){
		/*create new array of threads 
		"at" stands for array of threads*/
		pthread_t at[NUM_THREADS];
		for(i=0;i<NUM_THREADS;i++){
			/*allocates the second pointer targs*/
			p1=(targs*)malloc(sizeof(targs));
			/*checks for error in malloc*/
			if( p1 == NULL ){
	                        printf("Error: malloc failed. ");
        	                /*end thread*/
	                        pthread_exit(NULL);
			}

			/*assign targs arguments*/
			p1->N = p->N-1;
			p1->Index=i;
			strcpy(p1->Str,"Hello!");
			
			/*create new thread*/
			rc= pthread_create(&at[i], NULL, TAction, p1);
			/*check for error*/
			if(rc){
                	   	 printf("Error: pthread_create failed.");
                		 printf("returned code: %d\n", rc);
        	       		 /*exit prog*/
	               		 exit(1);
                	}
		}

		/*join created threads*/
		for(i=0; i<p->N;i++){
			rc= pthread_join(at[i], (void**)&p1);
			if(rc){
				printf("Error: pthread_join failed.");
                        	printf("returned code: %d\n", rc);
                        	/*exit prog*/
                        	exit(1);
			}

			/*print received str*/
			printf("Received \"%s\"\n", p1->Str);
			fflush(stdout);
			free(p1);
		}
	}

	sprintf(p->Str, "%i %i", p->N, p->Index);
	pthread_exit(p);
}

int main(void){ 
	/*Array of the first 4 threads*/
	pthread_t st[NUM_THREADS];
	/*
	 * rs -> rs means returned code which we use
	 * to check if a function ( for example pthread_create ) fails
	 * we then print an error message and end the code
	 */
	int rc;
	int i;
	/*
	 * creating pointer to targs struct,
	 * this pointer will be given to pthread_create
	 * ("pt" stands for pointer targs)
	 */
       targs *pt;	
       /*Initialize random number generator*/
       srand(time(NULL));

       /*creating the first 4 threads*/
       for(i=0;i<NUM_THREADS;i++){
       		/*allocating memory for the struct targs*/
		pt=(targs*)malloc(sizeof(targs));
		/*checks for problem during memory allocation*/
		if(pt == NULL){
			printf("Error: malloc failed. ");
			/*end main thread*/
			pthread_exit(NULL);
		}
		/*assigning all struct tagrs's arguments*/
		pt->N= NUM_THREADS-1;
		strcpy(pt->Str,"String for testing!");
		pt->Index=i;

		printf("Creating thread n(%d)...\n",i);
		fflush(stdout);
		/*Create thread*/
		/*
		 * first argument is the array for threads, second is just NULL
		 * third is the function that will be all the actions done
		 * by this thread, fourth is the arguments struct pointer
		 */
		rc= pthread_create( &st[i], NULL, TAction, pt);
       		/*Check for pthread_create error*/
		if(rc){
			printf("Error: pthread_create failed.");
			printf("returned code: %d\n", rc);
			/*exit prog*/
			exit(1);
		}
       }

       /*join previous created threads*/
       for(i=0;i<NUM_THREADS;i++){
       		/*join threads*/
		rc= pthread_join(st[i], (void*)&pt);
	      	/*check for pthread_join error*/
		if(rc){
                        printf("Error: pthread_join failed.");
                        printf("returned code: %d\n", rc);
                        /*exit prog*/
                        exit(1);
                }

		/*print received Str*/
		printf("Main received: \"%s':\n", pt->Str);
       		fflush(stdout);
		free(pt);
       }

       /*End main thread*/
       printf("End of main.\n");
       pthread_exit(NULL);
       return(0);
}	

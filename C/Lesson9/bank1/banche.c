#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>

#include "printerror.h"
#include "DBGpthread.h"

#define NUMBANCHE 3
#define NUMDEPOSITIPERBANCA 5 
#define NUMPRELIEVIPERBANCA 4
/* variabili da proteggere */
double T[NUMBANCHE]={0.0, 0.0, 0.0 };
int    N[NUMBANCHE]={0,0,0};

/* variabili per la sincronizzazione */
pthread_mutex_t  mutex;

void *Depositi (void *arg) 
{ 
	char Clabel[128];
	intptr_t indicebanca;

	indicebanca=(intptr_t)arg;
	sprintf(Clabel,"D%" PRIiPTR "" , indicebanca);

	while(1) 
	{
		struct timespec ts={0, 100000000L }; /* 1/10 sec */

		sleep(1);
		DBGpthread_mutex_lock(&mutex,Clabel); 
		T[indicebanca] += 10.0;
		N[indicebanca] ++;
		printf("Deposito: N %d  T %f \n", N[indicebanca], T[indicebanca] );
		fflush(stdout);
		nanosleep(&ts,NULL);

		DBGpthread_mutex_unlock(&mutex,Clabel); 
	}
	pthread_exit(NULL); 
} 

void *Prelievi (void *arg) 
{ 
	char Clabel[128];
	intptr_t indicebanca;

	indicebanca=(intptr_t)arg;
	sprintf(Clabel,"P%" PRIiPTR "" , indicebanca);

	while(1) 
	{
		struct timespec ts={0, 100000000L }; /* 1/10 sec */

		sleep(1);
		DBGpthread_mutex_lock(&mutex,Clabel); 
		T[indicebanca] -=9.0 ;
		N[indicebanca] ++;
		printf("Prelievo: N %d  T %f \n", N[indicebanca], T[indicebanca] );
		fflush(stdout);
		nanosleep(&ts,NULL);

		DBGpthread_mutex_unlock(&mutex,Clabel); 
	}
	pthread_exit(NULL); 
} 

void *BancadItalia (void *arg) 
{ 
	char Clabel[128];

	sprintf(Clabel,"BancadItalia" );

	while(1) 
	{
		int i;  int Num=0; double sum=0.0;

		DBGpthread_mutex_lock(&mutex,Clabel); 
		for( i=0; i<NUMBANCHE; i++ ) {
			Num += N[i];
			sum += T[i];
		}
		DBGpthread_mutex_unlock(&mutex,Clabel); 
		printf("Report BancaDItalia: Num %d  sum %f \n", Num, sum);
		fflush(stdout);

		sleep(30);
	}
	pthread_exit(NULL); 
} 

int main (int argc, char* argv[] ) 
{ 
	pthread_t   th; 
	int  rc;
	intptr_t i,k;

	rc = pthread_mutex_init( &mutex, NULL); 
	if( rc ) PrintERROR_andExit(rc,"pthread_mutex_init failed");

	for(i=0;i<NUMBANCHE;i++) {
		/* lancio  thread Depositi */
		for(k=0;k<NUMDEPOSITIPERBANCA;k++) {
			rc=pthread_create( &th, NULL,Depositi,(void*)i); 
			if(rc) PrintERROR_andExit(rc,"pthread_create failed");
		}
		/* lancio  thread Prelievi */
		for(k=0;k<NUMPRELIEVIPERBANCA;k++) {
			rc=pthread_create( &th, NULL,Prelievi,(void*)i); 
			if(rc) PrintERROR_andExit(rc,"pthread_create failed");
		}
	}

	/* lancio thread BancadItalia */
	rc=pthread_create( &th, NULL,BancadItalia,(void*)k); 
	if(rc) PrintERROR_andExit(rc,"pthread_create failed");

	pthread_exit(NULL); 

	return(0); 
} 

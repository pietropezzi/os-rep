/*
 * Esercizio per spiegarie le condition variables con la volpe e
 * la galline 
 */
#ifndef _THREAD_SAFE
#define _THREAD_SAFE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <inttypes.h>

int uova=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *gallina(void *arg){
	while(1) {
		/*
		 * Prende il "turno" per la uova e la deposita
		 */
		pthread_mutex_lock(&mutex);
		uova++;
		printf("Ho cagato un uovo! spero che un infame non me lo mangi!\n");
		/* Manda a un segnale a chi altro sta aspettando di usare la
		 * mutex delle uova, in questo caso la volpe
		 */
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex); 
	}
}

void *volpe(void *arg){
	while(1){
		int mangiato=0;
		pthread_mutex_lock(&mutex);
		while(!mangiato){
			if( uova>0 ){
				/* mangia(); qui ci andrebbe la funzione da eseguire */ 
				printf("volpe infami si mangia l'uovo!\n");
				uova--;
			} else {
				/* attende un segnale , intanto rilascia la mutex per chi
				 * ne ha bisogno!
				 */
				pthread_cond_wait(&cond, &mutex);
			}
		}
		pthread_mutex_unlock(&mutex);
		printf("scorreggiona da parte della volpe\n");
		/*miticoruttone(); */
	}
}

int main(){
	pthread_t tid;
	pthread_create( &tid, NULL, gallina, NULL);
	pthread_create( &tid, NULL, volpe, NULL);
	pthread_exit(NULL);
}

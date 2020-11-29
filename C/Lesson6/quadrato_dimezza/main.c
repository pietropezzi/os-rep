#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "quadrato.h"
#include "dimezza.h"

static double salva=0.0;

int main(void){
	double n=13.17;

	salva=quadrato(dimezza(n));
	printf("Il quadrato della meta del coseno di %f e': %f\n",n,salva);
	
	return(0);
}

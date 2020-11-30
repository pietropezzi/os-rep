#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "../INCLUDE/dimezza.h"

static double salva = 0.0;

double dimezza(double num){
	salva=(cos(num))/2.0;
	return(salva);	
}


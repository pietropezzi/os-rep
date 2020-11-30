#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../INCLUDE/quadrato.h"

static double salva = 0.0;

double quadrato(double num){
	salva=num*num;
	return(salva);
}


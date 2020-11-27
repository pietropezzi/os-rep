#!/bin/bash

#this is the number the teacher uses in his solutions
RANDOM=$(( `date +%s` % 32768 ))
#number of times random was read
N_RAND=0;

#checks for the condition
while (( ${RANDOM}%10 != 2 )) ; do
	(( N_RAND=${N_RAND}+1 ))
done

#prints how many times random was read
echo "RANDOM was read ${N_RAND} times"



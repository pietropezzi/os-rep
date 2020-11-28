#!/bin/bash

#number of times hes going to start the script
REPEAT=10

for (( N=0;${N}<${REPEAT};N=${N}+1 )) ; do
	#start 'puntini,sh' for 30 secs in the background
	. ../puntini.sh 30 1>&2 &
	echo -n "$! " ;
done


#!/bin/bash

if (( $# != 1 )) ; then echo "You need to enter 1 integer!" ; exit 1 ; fi

N=1

while (( ${N}<=$1 )) ; do
	sleep 1
	echo " . ${BASHPID}"
	(( N=${N}+1 ))
done 


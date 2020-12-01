#!/bin/bash

N=0
( PIDBASHGROUP=${BASHPID} ; tail -n 10000 --pid=${PIDBASHGROUP} -f 8.txt | 
	while read ROW ; do
		((N=${N}+1)); if [[ ${ROW} == "k" ]] ; then
		echo NUM ROW ${N} ; kill -SIGKILL ${PIDBASHGROUP}; exit 0; fi;
	done )

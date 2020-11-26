#!/bin/bash

N=$1
if (( ${N} > 1 )) ; then
	(( RESULT=${RESULT}*${N} ))
	(( N=${N}-1 ))
	source ./fattoriale.sh "${N}"
fi

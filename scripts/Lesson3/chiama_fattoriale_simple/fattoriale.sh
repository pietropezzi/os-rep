#!/bin/bash

N=1
RESULT=1

#this while calculates the factorial of the input number
while (( ${N} <= $1 )) ; do
      (( RESULT=${RESULT}*${N} ))
      (( N=${N}+1 ))
done

#print the result
echo ${RESULT}


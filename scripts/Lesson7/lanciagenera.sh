#!/bin/bash

if [[ -e out.txt ]] ; then
	rm -f out.txt
fi

for (( N=0;${N}<10;N=${N}+1 )) ; do
	./genera.sh out.txt
done

RESULT=0
while read VALUE OTHER ; do
	(( RESULT=${RESULT}+${VALUE} ))
done < out.txt

echo ${RESULT}

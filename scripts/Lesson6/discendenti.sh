#!/bin/bash
if (( "$#" != "1" )) ; then
	echo "you need to enter a number!"
	exit 1
fi

if (( "$1" < "0" )) ; then
	echo "you need to enter a positive number!"
	exit 1
fi

REPEAT=$1

for (( i=0;$1<${REPEAT};i=$1+1 )) ; do
	. discengenti.sh $(( ${REPEAT}-1 )) &
done

for (( i=0; $i<${REPEAT};i=$i+1 )) ;do
	wait
done

echo "${REPEAT}"


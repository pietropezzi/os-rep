#!/bin/bash

read DEFINE SIM VALUE OTHER < ./define.h
echo ${VALUE}

rm -r variabiliglobali.c

for (( N=1;${N}<=${VALUE};N=${N}+1 )) ; do
	echo "int var${N} = ${N};" >> variabiliglobali.c
done

echo "int conta(void){" >> variabiliglobali.c
echo -n "int sum=0" >> variabiliglobali.c
for (( N=1;${N}<=${VALUE};N=${N}+1 )) ; do
	echo -n "+var${N}" >> variabiliglobali.c
done
echo ";" >> variabiliglobali.c
echo "return(sum);" >> variabiliglobali.c
echo "}" >> variabiliglobali.c
echo ""


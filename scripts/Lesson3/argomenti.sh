#!/bin/bash

RES=""
N=0

#even index
for (( N=2;${N}<=$#;N=${N}+2 )) ; do
	RES="${RES}${!N}";
done

#odd index
for (( N=1;${N}<=$#;N=${N}+1 )) ; do
	RES="${RES}${!N}";
done

#print the result
echo ${RES}

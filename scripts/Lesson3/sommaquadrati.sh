#!/bin/bash

QUAD=0
SUMM=0
INDEX=0
RESULT=0
N=0

#quad summ
for (( N=1;${N}<=$#;N=${N}+1 )) ; do
	(( QUAD=${!N}*${!N} ))
       	(( SUMM=${SUMM}+${QUAD} ))
done

#index summ
for (( N=1;${N}<=$#;N=${N}+1 )) ; do
	(( INDEX=${INDEX}+${N} ))
done

(( RESULT=${SUMM}-${INDEX} ))
echo ${RESULT}


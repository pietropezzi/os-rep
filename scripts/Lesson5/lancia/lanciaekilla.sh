#!/bin/bash 

#get all the pids
PIDS= `. lanciaeprendipid.sh `

#print them
echo ${PIDS}

#kill them
for pid in ${PIDS} ; do
	kill -9 ${pid};
done


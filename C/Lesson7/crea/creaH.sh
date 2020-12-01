#!/bin/bash

read DEFINE SIM VALUE OTHER < ./define.h

echo ${VALUE}

#removes the file if it already exists
rm -f variabiliglobali.h
for (( N=1; ${N}<=${VALUE};N=${N}+1 )) ; do
	echo "extern int var${N};" >> variabiliglobali.h
done
echo "extern int conta(void);" >> variabiliglobali.h

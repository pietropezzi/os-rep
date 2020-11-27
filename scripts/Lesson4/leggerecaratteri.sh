#!/bin/bash

#open file
exec {FD}< /usr/include/stdio.h

N=0

#checks if file was correctly opened
if (( $? == 0 )) ; then
	#reads each character of a line of the file
	while read -u ${FD} -N 1 -r A ; do
		(( N=${N}+1 ))
	done
	#close file
	exec {FD}>&-
	#print the count
	echo ${N}
fi #close if	

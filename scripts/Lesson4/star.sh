#!/bin/bash

#file should already be open since in
#the argument when i run the script
while (( 1 )) ; do
	#first 4 words
	read first second third fourth
	#check for error while reading words
	if (( $? == 0 )) ; then
		echo "${fourth} ${third}"
	else
		#if there was an error break the while
		break
	fi
done

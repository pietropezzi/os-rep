#!/bin/bash

REST=${PATH}

#this script separetes all the current path locations
while [[ -n ${REST} ]] ; do
	#a location is from start to the :
	FIRST_LOC=${REST%%:*}
	echo ${FIRST_LOC}
	
	PRE_REST=${REST}
	#re assign REST from new location
	REST=${REST#*:}
		
	#checks if theres more locations
	if [[ ${PRE_REST} == ${REST} ]] ; then
		break
	fi
done

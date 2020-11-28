#!/bin/bash

REVERSE=""

#reverses the argument given in unput
echo $1 | while (( 1 )) ; do
		read -N 1 C ;
		#error check in the read process
		if (( $? == 0 )) ; then
			REVERSE=${C}${REVERSE}
		else
			echo "reversed argument: ${REVERSE}"
			break
		fi #end if
	done

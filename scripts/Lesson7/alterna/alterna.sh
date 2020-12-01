#!/bin/bash

if (( $# != 2 )) ; then
	echo "You need to  enter 2 files name!"
	exit 1
fi

#out.txt already exists, delete it
if [[ -e out.txt ]] ; then
	rm -f out.txt
fi

exec {FD1}<$1
exec {FD2}<$2

CURR_FD=${FD1}
while read -u ${CURR_FD} STRING_READ ; CHECK_ERR=$? ; 
	[[ ${STRING_READ} != "" || ${CHECK_ERR} -eq 0 ]] ; do
	echo "${STRING_READ}" >> out.txt
	if (( ${CHECK_ERR} != 0 )) ; then
	       break
	else	
		if (( CURR_FD == ${FD1} )) ; then
			CURR_FD=${FD2}
		else 
			CURR_FD=${FD1}
		fi
	fi
done
#if it exists it means that one of the FD is done

if (( ${CURR_FD}==${FD1} )) ; then
	exec {FD1}>&-
	CURR_FD=${FD2}
else
	exec {FD2}>&-
	CURR_FD=${FD1}
fi

#closed the one thats done we have to finish the other one

while read -u ${CURR_FD} STRING_READ ; CHECK_ERR=$? ; 
	[[ ${STRING_READ} != "" || ${CHECK_ERR} -eq 0 ]] ; do
	echo "${STRING_READ}" >> out.txt
	if (( ${CHECK_ERR} != 0 )) ; then
		break
	fi
done

exec {CURR_FD}>&-
echo DONE!


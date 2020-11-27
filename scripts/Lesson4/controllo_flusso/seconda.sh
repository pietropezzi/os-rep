#!/bin/bash

RES=""

#check if theres an argument
if (( $# != 1 )) ; then
	echo "You need to enter an argument!"
	exit 1
fi

#the file name that was given in the argument
#need to be checked (if it actually exists)
if [[ ! -r $1 ]] ; then
	echo "The argument you entered is not a valid file name!"
	exit 2
fi

while read first second third ; do
	if [[ -n ${second} ]] ; then
		RES=${RES}${second}
	fi
#done and close file
done < $1
echo "RESULT: ${RES}"

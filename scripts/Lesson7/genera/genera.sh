#!/bin/bash

if (( $# != 1 )) ; then 
	echo "You need to enter 1 file!"
	exit 1
fi

echo $( ./random09.sh ) >> $1

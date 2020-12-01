#!/bin/bash

for PATH in `find /usr/include/ -mindepth 1 -type f` ; do
	NAME=${PATH##*/}
	if (( ${#NAME} >= 7 )) ; then
		echo ${NAME:6:1} >> 7.txt
		if (( ${#NAME} >= 8 )) ; then
			echo ${NAME:7:1} >> 8.txt ;
		fi
	fi
done

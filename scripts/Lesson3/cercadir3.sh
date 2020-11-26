#!/bin/bash

#this is just another version of 'cercadir.sh' using test instead of [[ ]]

for file in `ls /usr/include` ; do
	#we have to do the same thing we did for [ ]
	if test -d /usr/include/${file} -a 	\
	      -r /usr/include/${file} -a 	\
	      /usr/include/${file} -nt /usr/include/stdio.h ;
		then
		echo ${file}
	fi #end if
done #end for


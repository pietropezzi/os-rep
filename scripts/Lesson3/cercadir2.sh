#!/bin/bash

#the difference between 'cercadir.sh' and this one is the usage of [ ] in the for instead of [[ ]]

for file in `ls /usr/include` ; do
	#using [] instead of [[ ]] makes the \ essential 
	#we also need -a
	if [ -d /usr/include/${file} -a 	\
	      -r /usr/include/${file} -a 	\
	      /usr/include/${file} -nt /usr/include/stdio.h ];
		then
		echo ${file}
	fi #end if
done #end for


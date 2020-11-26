#!/bin/bash

for file in `ls /usr/include` ; do
	#now i check if all these files respect the conditions.
	if [[ -d /usr/include/${file} && 	\
	      -r /usr/include/${file} && 	\
	      /usr/include/${file} -nt /usr/include/stdio.h ]];
	#conditions: file must be a directory, fil must have read permission 
	#and the file's last edit date must be more recent than 
	#/usr/include/stdio.h's date.
		then
	#if all conditions are approved , print the file's path.
		echo ${file}
	fi #end if
done #end for

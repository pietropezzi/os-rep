#!/bin/bash

#for each letter in c to g
for char in {c..g} ; do 
	#look for the files in the /usr/include folder that have
	#that letter as the second character in their name.
	for file in /usr/include/?${char}* ; do
		#now i need to check if the files respect these conditions
		#the file's path lenght must be less than 18 or greater than 23
		if [[ ${#file} -lt 18 || ${#file} -gt 23 ]] ; 
			then
			#if all the conditiond are approved, print
			#the file's path.
			echo ${file}
		fi #endif
	done #end file for
done #end char for

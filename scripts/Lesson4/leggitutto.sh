#!/bin/bash

#open file
exec {FD}< ./miofileNoNL.txt

#check for error
if (( $? == 0 )) ; then
	#it reads each row, before printing a row it checks if there was 
	#an error and if the row is empty.
	while read -u ${FD} ROW ; [[ $? == 0 || ${ROW} != "" ]] ; do
		echo ${ROW}
	done
	#close file
	exec {FD}>&-
fi #end if

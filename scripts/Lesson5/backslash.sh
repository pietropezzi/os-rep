#!/bin/bash

#this script detects * ? [ ] and puts a \ in the output result

while read IN_LINE ; do
	INDEX=0
	RESULT=""
	while (( ${INDEX} < ${#IN_LINE} )) ; do
		#char is a character in the input line
		CHAR=${IN_LINE:${INDEX}:1}
		#check for * ? [ and ]
		if [[ ${CHAR} == "*" || ${CHAR} == "?" || ${CHAR} == "[" || ${CHAR} == "]" ]] ; then
			#if it detects one of those characters
			#then it puts a \\ in front of it in the
			#output phrase
			RESULT="${RESULT}\\${CHAR}"
		else
			#if its not one of those character
			#then it just adds the char
			RESULT="${RESULT}${CHAR}"
		fi #end if
		(( INDEX=${INDEX}+1 ))
	done #end char reading while
	#print result
	echo "###RESULT >> ${RESULT}"
done #end LINE while

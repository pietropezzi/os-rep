#!/bin/bash

while read LINE ; do
	#i use "" to ignore eventual * ; / :-)
	#i also grab the first word 
	WORD_TO_PRINT="${LINE%%*}"
	#print word in standard err
	echo "${WORD_TO_PRINT}" 1>&2
	#also print evviva for each word print
	echo "evviva!"
done 

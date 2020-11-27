#!/bin/bash

#checks for 'A' in each row of the file given
#if a row contains 'A' the script prints the numbers of characters.
while read RIGA ; do
	 grep A $1 | wc -c  
done < $1


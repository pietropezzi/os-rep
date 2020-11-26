#!/bin/bash

N=$#
while (( ${N} > "0" )) ; do
	echo "argument number ${N} is ${!N}."
	(( N=${N}-1 )) 
done	

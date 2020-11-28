#!/bin/bash

while read ID DESCVER ; do
	while read ID_COMPLAINT ID_PROCESS ; do
		if [[ ${ID} == ${ID_PROCESS} ]] ; then
			while read NAME SURNAME IDCOM DESC ; do
				if [[ ${ID_COMPLAINT} == ${IDCOM} ]] ; then
					echo ${NAME} ${SURNAME} ${DESC} ${DESCVER} 
					break
				fi
			done < denunce.txt
			break
		fi
	done < processi.txt
done < verdetti.txt

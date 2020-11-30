#!/bin/bash

SEARCH=`find /usr/include/linux -mindepth 2 -name *.h* -print`
if [[ -z ${SEARCH} ]] ; then
	echo "No files found!"
else
	for CURR in ${SEARCH} ; do
		break
	done

	for NAME in ${SEARCH} ; do
		if [[ ${CURR} -ot ${NAME} ]] ; then
			CURR=${NAME}
		fi
	done
fi
echo "The most recently edited file is ${NAME}"

DATE_OF_NAME=`date -r ${NAME}`
echo "It was last edited in ${DATE_OF_NAME}"

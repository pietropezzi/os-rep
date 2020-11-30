#!/bin/bash

while read NAME SURNAME ID GRADE ; do
	if (( "${GRADE}" < "18" )) ; then
		LINES=`grep ${ID} RisultatiProvaPratica1.txt | wc -l`
		if [[  "${LINES}" == "0" ]] ; then
		       echo ${ID} ${NAME} ${SURNAME} ${GRADE}
		fi
	fi
done < RisultatiProvaPratica2.txt | sort | cut -d '' -f2


#!/bin/bash

CURR=${PATH}

#checks if theres something in CURR
while [[ -n ${CURR} ]] ; do
	#first char in the path
	CHAR=${CURR:0:1}
	
	#since whe are checking a path we have to make sure the char is not
	#a separator ( checks if its / or : )
	if [[ ${CHAR} == "/" || ${CHAR} == ":" ]] ; then
		#if its a "forbidden character the script skips to 
		#the next chachter
		CURR=${CURR:1}
	else
		#not a "forbidden" char
		#we are in the "middle" of the charachters : or /
		#for example if we are readin /bin:/ we are in the b,
		#so no we have to "grab" only the bin part, to do this
		#i will use use two vars

		#to grab the first chunk we grab the part until the : char
		#but we also have to grab the part until the / char since
		#we dont know wich one of the two we have next!
		CHUNK1=${CURR%%:*}
		CHUNK2=${CURR%%/*}

		#now to check wich one is correct we just check the lenght 
		#one of those two is empty!
		if (( ${#CHUNK1} < ${#CHUNK2} )) ; then
			CHUNK=${CHUNK1}
		else
			CHUNK=${CHUNK2}
		fi
		echo ${CHUNK}

		#now we have to update the char to check
		OFFSET=$(( ${#CHUNK}+1 ))
		#we basically move the CURR to 1 next to the just return part
		CURR=${CURR:${OFFSET}}
	fi
done


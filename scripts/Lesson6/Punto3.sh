#!/bin/bash 
ROW="1 * 2"

while [[ -n "${ROW}" ]] ; do
	WORD="${ROW%% *}"
	if [[ "${WORD}" == "${ROW}" ]] ; then
		ROW=
	else
		ROW="${ROW#* }"
	fi
	echo "WORD is ${WORD}"
done

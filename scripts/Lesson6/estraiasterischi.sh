#!/bin/bash

sleep 2

TUTTO=

while read ROW ; do
	ROW="${ROW# }"
	while [[ -n "${ROW}" ]] ; do
		WORD="${ROW%% *}"
		if [[ "${WORD}" == "${ROW}" ]] ; then
			ROW=
		else
			ROW="${ROW#* }"
		fi
		if echo "${WORD}" | grep '*' > /dev/null ; then
			TUTTO="${TUTTO} ${WORD}"
		fi
	done
done
echo "${TUTTO}"

#!/bin/bash

caughtSIGUSR2(){
	if read ROW ; then
		echo "DUE ${ROW}"
		kill -s SIGUSR2 ${PID1}
	else
		kill -s SIGUSR2 ${PID1}
		exit 0
	fi
}

trap caughtSIGUSR2 SIGUSR2

echo ${BASHPID} > due.pid.txt
sleep 2

read PID1 < uno.pid.txt

while true ; do
	sleep 1
done

#!/bin/bash

caughtSIGUSR2(){
	if read ROW ; then
		echo "UNO ${ROW}"
		kill -s SIGUSR2 ${PID2}
	else
		kill -s SIGUSR2 ${PID2}
		exit 0
	fi
}

trap caughtSIGUSR2 SIGUSR2

echo ${BASHPID} > uno.pid.txt
sleep 2

read PID2 < due.pid.txt

if read ROW ; then
	echo "UNO ${ROW}"
	kill -s SIGUSR2 ${PID2}
else
	kill -s SIGUSR2 ${PID2}
	exit 1
fi

while true ; do
	sleep 1
done

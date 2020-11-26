#!/bin/bash

N=1
while (( ${N} <= $# )) ; do
	echo "argument number ${N} is ${!N}"
	((N=${N}+1))
done
. script2.sh "$@"


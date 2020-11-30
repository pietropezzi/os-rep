#!/bin/bash

. estraiasterischi.sh < input.txt &

LAUNCH_PID=$!
echo done &
wait ${LAUNCH_PID}

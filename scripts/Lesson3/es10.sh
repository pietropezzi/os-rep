#!/bin/bash

for file in * ; do
	echo "file is ${file}"
	ls -ld ${file}
done

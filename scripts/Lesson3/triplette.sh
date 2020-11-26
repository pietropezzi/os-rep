#!/bin/bash

FILES=`ls`

for file1 in ${FILES} ; do
	for file2 in ${FILES} ; do
		for file3 in ${FILES} ; do
			echo \(${file1}\;${file2}\;${file3}\) ;
		done
	done
done


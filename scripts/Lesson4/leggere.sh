
#!/bin/bash

#open file to read
exec {FD}< /usr/include/stdio.h

#if opening the file did not return eny error
if (( $? == 0 )) ; then
	#while readiang each row and associating each word (first 4 words)
	while read -u ${FD} A B C D ; do
		#print the third word
		echo ${C}
	done
	#close file
	exec {FD}>&-
fi #end if


#!/bin/bash

#this script does the same thing as 'es1.sh'
#the only different thing is the for part.

mkdir BUTTAMI
touch BUTTAMI/"*" BUTTAMI/"**" BUTTAMI/"***" BUTTAMI/";;"

for file in "`ls BUTTAMI/*`" ; do
	touch "$file".txt ;
done 

mkdir BUTTAMI/copia
cp -R /usr/include BUTTAMI/copia
find ./BUTTAMI -type d

rm -rf BUTTAMI/copia/include

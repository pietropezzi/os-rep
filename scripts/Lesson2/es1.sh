#!/bin/bash

mkdir BUTTAMI
touch BUTTAMI/"*" BUTTAMI/"**" BUTTAMI/"***" BUTTAMI/";;"

#for each file in the BUTTAMI folder
for file in BUTTAMI/* ; do
	#create a .txt file with each file name
	touch "$file".txt ;
done

#creates a 'copia' folder and then copies /usr/incled files in it
mkdir BUTTAMI/copia
cp -R /usr/include BUTTAMI/copia
find ./BUTTAMI -type d

#deletes the iclude folder in copia
rm -rf BUTTAMI/copia/include

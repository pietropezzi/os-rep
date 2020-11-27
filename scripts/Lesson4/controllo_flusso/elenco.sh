#this scripts checks for all the files/dirs in the current
#checks if it's a directory and then it counts the lenght of the
#folder name. all the names lenght are added together, the script also
#counts all non directory files

DIR_NAME_LENGHT=0
NO_DIR=0
LOCATION="./"

for name in `ls ${LOCATION}` ; do
        #checks if the file is a directory
        if [[ -d ${name} ]] ; then
                #if its a directory it increases the DIR_NAME_LENGHT counter
                #' ${#name} returns the directory's name lenght
                (( DIR_NAME_LENGHT=${DIR_NAME_LENGHT}+${#name} ))
        else
                #file is not a directory
                (( NO_DIR=${NO_DIR}+1 ))
	fi
done

#print the results
echo "CURRENT LOCATION: '${LOCATION}'"
echo "DIRECTORY'S NAMES LENGHT SUMM: ${DIR_NAME_LENGHT}"
echo "NUMBER OF NON DIR FILES: ${NO_DIR}"

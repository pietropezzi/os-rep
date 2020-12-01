#!/bash/bin

if [[ -e 7.txt ]] ; then 
	rm -f 7.txt
fi

if [[ -e 8.txt ]] ; then
	rm -f 8.txt 
fi

touch 7.txt 8.txt

./leggi7.sh 2> /dev/null &
./leggi8.sh 2> /dev/null &
./strippa1.sh


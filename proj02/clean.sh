#!/bin/sh
#clear.sh
#A shell script for cleaning out unused/
# unneeded files in a specified directory
#created by Bryce Allen for cs232 project 2 at Calvin College
#3/12/19

#delete() removes all the .o, ~, ##, .exe, and core files recursively 
#directory we want to clear will be the first and only parameter.
delete () {
    echo "Cleaning Directory"
	directory=$1
	directoryLength=$(echo -n $directory | wc -m)
	for i in "$1"/*
	 do
		#test each file and if it has the right extension -> delete
		
		poundLength=$(echo -n $(echo -n $i | grep -e'\#') | wc -m)
		tildaLength=$(echo -n $(echo -n $i | grep -e'\~') | wc -m)
		if [[ -d $i ]]; then
			delete $i
		elif [[ ${i##*.} = "o" ]]; then
			rm $i
			echo ${i} deleted.
		elif [[ $poundLength -gt 0 ]]; then
			rm $i
			echo ${i} deleted.
		elif [[ $tildaLength -gt 0 ]]; then
			rm $i
			echo ${i} deleted.
		elif [[ ${i##*.} = "exe" ]]; then
			rm $i
			echo ${i} deleted.
		elif [[ ${i##*/} = "core" ]]; then
			rm $i
			echo ${i} deleted.
		fi
	done
}

#main section iterates through all the command line arguments
#and will call delete when necessary
clean='clean'
for i in $@; do
	if [ $i = $clean ]; then
		delete $2
	fi
done

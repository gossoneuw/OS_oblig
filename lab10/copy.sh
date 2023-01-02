#! /bin/bash


sourcefile=$1
destfile=$2
numarg=$#
n=0
if [ $numarg != 2 ]; then
echo too few or too many arguments
exit
fi
if test -f "$sourcefile"; then
echo "$sourcefile exists."
else
echo "$sourcefile does not exist."
exit
fi
while read -r line; do
echo $line >> $destfile
n=$((n+1))
done < $sourcefile
echo "number of lines in sourcefile was $n" >> $destfile

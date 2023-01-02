# this is a simple Bash script
# The first line tells what type of file it is
#! /bin/bash

echo Doing something cool
sleep 2

# Changing directory
echo Changing directory
sleep 2

cd /home/tarjeisv/OS2022/labs
# print working directory
echo Printing working directory:
sleep 2
pwd

# Doing something fun
echo Updating the access and modification times of each FILE
sleep 2
echo A file argument that does not exist is created empty
sleep 2
touch a b c d e

# Doing something fun. Well, this is comment
echo Creating a new environment variable
sleep 2
export HELLO="Hallo!"
echo $HELLO

# Deleting file system
echo Deleting file system...
sleep 2
rm a b c d e
echo Done!


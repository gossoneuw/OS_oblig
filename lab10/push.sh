#! /bin/bash

echo Enter file to be added
read fileName
sleep 1


echo enter commit message.
read c_message
sleep 1

git add $fileName
sleep 1

git status
sleep 1

git commit -m "$c_message"
sleep 1

git push




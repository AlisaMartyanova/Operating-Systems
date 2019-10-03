#! /bin/bash

if [ $# -lt 1 ]
then
  echo "Specify the name of the executable file."
  echo "$0 filename"
  exit
fi

size $1 > ex1.txt

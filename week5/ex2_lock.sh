#!/bin/bash 
                                                   
if test ! -f ex2_numbers;
then
    echo 0 > ex2_numbers
fi


if ln ex2_numbers ex2_numbers.lock
  then                                                                    
  for i in `seq 1 100`;
  do
    LASTNUMBER=`tail -1 ex2_numbers`
    LASTNUMBER=$((LASTNUMBER+1))

    echo $LASTNUMBER >> ex2_numbers
  done


  rm ex2_numbers.lock
fi

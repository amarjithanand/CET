#!/bin/bash
read -p "Enter 3 numbers : " a b c
if [ $a -gt $b ] && [ $a -gt $c ]
then
    echo "$a is the greatest"
elif [ $b -gt $c ]
then
    echo "$b is the greatest"
else
    echo "$c is the greatest"
fi
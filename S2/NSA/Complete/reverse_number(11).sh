#!/bin/bash

read -p "Enter a number : " num
rev=0

while [ $num -gt 0 ]
do
    rem=$((num % 10))   # No space around = 
    rev=$((rev * 10 + rem))
    num=$((num/ 10))
done

echo "Reversed number : $rev"
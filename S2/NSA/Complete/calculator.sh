#!/bin/bash

echo "Select an operation : "
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

read -p "Enter choice : " choice
read -p "Enter 2 numbers " a b

case $choice in
    1)
        result=$((a + b))
        echo "$a + $b : $result"
        ;;

     2)
        result=$((a - b))
        echo "$a - $b : $result"
        ;;

     3)
        result=$((a * b))
        echo "$a * $b : $result"
        ;;

     4)
        #result=$((a / b))

        result=$(echo "scale=2; $a / $b" | bc)
        echo "$a / $b : $result"
        ;;
esac
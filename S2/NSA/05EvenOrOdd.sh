read -p"Enter a number :" n
if [ $(( $n % 2)) -eq 0 ]
then echo "Even"
else
    echo "Odd"
fi
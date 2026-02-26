read -p["Enter three numbers :"] a b c
if [ $a -gt $b ] && [ $a -gt $c]
then
    echo $a "is greater"
elif [ $b -gt $c ]
then
    echo $b "is greater"
else
    echo $c "is greater"
fi
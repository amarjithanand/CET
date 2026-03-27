read -p "enter a number: " n
f=1 
for i in $(seq 1 $n)
do
    f=$(($f * $i))
done
echo "factorial of " $n " = "$f

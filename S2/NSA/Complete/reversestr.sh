#!/bin/sh

echo -n "Enter a string: "
read s
l=${#s}
ns=""

i=$l
while [ $i -gt 0 ]; do
    a=$(expr substr "$s" $i 1)
    ns="$ns$a"
    i=$((i - 1))
done

echo "Reversed string: $ns"


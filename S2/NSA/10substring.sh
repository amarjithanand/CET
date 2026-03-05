#!/bin/bash
read -p"Enter the string :" str
read -p"Enter index and size of the string to extract :" a b
substr="${str:$a:$b}"
echo $substr
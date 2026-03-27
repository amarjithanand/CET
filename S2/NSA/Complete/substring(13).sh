#!/bin/bash

read -p "enter string : " str
read -p "enter starting index : " start
read -p "enter length of substring : " length

substr=${str:start:length}
echo "Substring : $substr"
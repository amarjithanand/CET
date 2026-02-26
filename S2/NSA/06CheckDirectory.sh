read -p "Enter the directory name" dir
for filename in "/mnt/c/Users/mca/Desktop/CET/S2/NSA/$dir"
do
    if [ -d "$filename" ]
    then
        echo "$filename is a directory"
    else
        echo "$filename is not a directory"
    fi
done

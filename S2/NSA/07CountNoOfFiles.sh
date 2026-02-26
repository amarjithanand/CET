read -p "Enter directory name you want to search: " dir 
direct="/mnt/c/Users/mca/Desktop/CET/S2/NSA/$dir"
if [ -d $direct ] 
then
num_files=$(find $direct -type f | ls -l $direct|
wc -l)
echo "There are $num_files files in $direct" 
else
echo "$direct is not a directory"
fi
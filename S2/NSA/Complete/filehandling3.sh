read -p "enter first file name:" file1
read -p "enter second file name:" file2
read -p "enter third file name:" file3
echo "enter the contents of $file1:"
cat > $file1 
echo "enter the contents of $file2:"
cat > $file2
echo "difference of $file1 and $file2 saved in $file3: "
diff -a $file1 $file2 > $file3
cat $file 3
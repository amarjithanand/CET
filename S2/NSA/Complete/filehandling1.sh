read -p "Enter a file name: " file1
echo "Enter contents of $file1:"
cat > "$file1"

read -p "Enter existing file name: " file2
echo "Displaying copy of contents from $file1 to $file2"

cp "$file1" "$file2"
cat "$file2"
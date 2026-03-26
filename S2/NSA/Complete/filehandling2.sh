read -p "Enter a file name: " file1

echo "Enter contents of $file1:"
cat > "$file1"

read -p "Enter line number: " line

echo "Start printing from line $line"

tail -n +$line "$file1"
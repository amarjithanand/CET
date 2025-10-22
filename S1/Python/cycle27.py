with open("file1.txt", "w") as f:
    f.write("Line 1\n")
    f.write("Line 2\n")
    f.write("Line 3\n")
    f.write("Line 4\n")
    f.write("Line 5\n")


with open("file1.txt", "r") as f, open("file2.txt", "w") as fw:
    for idx, line in enumerate(f):
        if idx % 2 == 0:
            fw.write(line)

with open("file2.txt", "r") as f:
    content = f.read()
    print("\nContents of file2.txt:")
    print(content)

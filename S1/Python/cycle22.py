n = int(input("Enter the number of rows for the upper half of the diamond: "))

for i in range(n):
    print(" " * (n-i-1),end="")
    print("*" * (2*i+1))

for i in range(n-2,-1, -1):
    print(" " * (n-i-1), end="")
    print("*" * (2*i+1))

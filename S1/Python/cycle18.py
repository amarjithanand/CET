def fact(n : int):
    if n<0:
        return "Enter an positive number!!!"
    if n==0:
        return 1
    else:
        return n*fact(n-1)

n = int(input("Enter the number to find factorial :"))
f = fact(n)
print(f)
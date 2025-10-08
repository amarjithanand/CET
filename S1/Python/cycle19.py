n = int(input("Enter the limit of fibonaci series :"))
a,b,c = 0,1,1
while c <= n:
    print(c)
    c = a + b
    a = b
    b = c

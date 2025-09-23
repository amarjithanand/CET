li=[]
n = int(input("Enter the number of elements"))
for i in range(n):
    li.append(int(input("Enter the numbers :")))
sq=[]
for i in li:
    sq.append(i**2)
print(sq)
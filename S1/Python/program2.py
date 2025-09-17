li=[]
posList=[]
n=int(input("Enter the number of elements :"))

for i in range(0,n):
    a = int(input("Enter the list element : "))
    li.append(a)
for i in li:
    if i > 0:
        posList.append(i)
    else:
        pass
print(posList)    
li = []
ch=""
while ch!='*':
    a = int(input("enter the list element :"))
    li.append(a)
    ch = input("Enter any character to continue , press * to exit :")
evenList=[]
for i in li:
    if i%2!=0:
        evenList.append(i)
    else:
        pass
print(evenList)
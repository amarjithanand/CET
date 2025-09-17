str = input("Enter the string : ")
str = str.lower()
li=[]
for i in str:
    if i in ['a','e','i','o','u']:
        li.append(i)
print(li)
str = input("Enter a line of text :")
li = str.split(" ")
li.sort()
se =set(li)
for x in se:
    i = 0
    for y in li:
        if x==y:
            i=i+1
    print(x," : ", i)
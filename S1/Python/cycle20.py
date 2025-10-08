str = input("Enter the string :")
li =[]
for i in str:
    li.append(i)
se = set(li)
for i in se:
    count = 0
    for j in li:
        if i == j:
            count = count + 1

    print(f"{i}  :  {count}")

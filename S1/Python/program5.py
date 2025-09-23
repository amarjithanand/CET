li=[]
ch = input("Enter the name : (press * to end)")
eq = "*"
while(ch != eq):
    if ch!= eq:
            li.append(ch)
    ch = input("Enter the name : (press * to end)")
    if ch==eq:
        print(li)
i = 0
for x in li:
     for y in x:
          if y in ['a','A']:
               i=i+1

print(f"Total occurence of 'A' is {i}")
        
li=[]
ch = input("Enter the colours  : (press * to end)")
eq = "*"
while(ch != eq):
    if ch!= eq:
            li.append(ch)
    ch = input("Enter the colours  : (press * to end)")
    if ch==eq:
        break
print(f"First color :{li[0]}")
print(f"Last color :{li[-1]}")

li=[]
ch = input("Enter the elements : (press * to end)")
eq = "*"
while(ch != eq):
    if ch!= eq:
        if (int(ch)<100):
            li.append(int(ch))
        else:
            li.append("Over")
    ch = input("Enter the elements : (press * to end)")
    if ch==eq:
        print(li)
    
        
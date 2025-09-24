se=set()
ch = input("Enter the elements : (press * to end)")
eq = "*"
while(ch != eq):
    if ch!= eq:
            se.add(ch)
    ch = input("Enter the name : (press * to end)")

de_set = sorted(se,reverse=True)
as_set = sorted(se)

print(f"Descending Order : {de_set}")
print(f"Ascending Order : {as_set}")


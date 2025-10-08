data = dict()
ch = input("Enter any character to start : (press * to end) ")
eq = "*"

while ch != eq:
    key = input("Enter ID : ").strip()
    value = input("Enter value :").strip()
    data[key] = value
    ch = input("Enter any character to continue : (press * to end) ")

de_data = sorted(data.items(), reverse=True)  
as_data = sorted(data.items()) 

print("Descending Order :")
for key, value in de_data:
    print(f"{key} : {value}  | ",end="")

print("Ascending Order :") 
for key, value in as_data:
    print(f"{key} : {value}  | ",end="")

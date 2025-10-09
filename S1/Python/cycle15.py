
data1 = dict()
ch = input("Enter any character to start : (Press * exit)")
eq = '*'
while (ch!=eq):
    key = input("Enter the key :")
    value = input("Enter the value for the key :")
    data1[key]=value
    ch = input("Enter any character to continue : (Press * exit)")
data2 = dict()
ch = input("Enter any character to start : (Press * exit)")
while (ch!=eq):
    key = input("Enter the key :")
    value = input("Enter the value for the key :")
    data2[key]=value
    ch = input("Enter any character to continue : (Press * exit)")
mergedDict = dict()
for key,value in data1.items():
    mergedDict[key] = value
for key,value in data2.items():
    mergedDict[key]=value

print("Merged Dictionary is :")
for key,value in mergedDict.items():
    print(f"{key} : {value}")
 
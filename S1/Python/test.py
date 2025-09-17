# num = int(input("Enter the number :"))
# if num%2==0:
#     print(f"{num} is an even number")
# else:
#     print(f"{num} is an odd number")

#######################################

year = int(input("Enter the year :"))
if year%400==0:
    print(f"{year} is a leap year")
elif (year%100==0):
    print(f"{year} is not a leap year") 
elif year%4==0:
    print(f"{year} is a leap year")
else:
    print(f"{year} is not a leap year")
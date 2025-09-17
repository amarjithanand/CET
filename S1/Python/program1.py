
from datetime import date

def leapYear(startYear,currentYear):
    year = startYear
    while(year<=currentYear):
        if year%400==0:
            print(year)
        elif year%100==0:
            pass 
        elif year%4==0:
            print(year)
        else:
            pass
        year=year+1

currentYear = date.today().year
startYear = int(input("Enter the starting year :"))
leapYear(startYear,currentYear) 

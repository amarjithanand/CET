a,b,c = input("Enter the value for a, b, c :").split()
a,b,c = int(a),int(b),int(c)
d = (b**2) - (4*a*c)
if d<0:
    print("Roots are Imaginary")
elif d>0:
    print("Roots are Real and Different , They are :",end=" ")
    print(f"{-b+(d/(2*a))} and {-b-(d/(2*a))}")
else:
    print("Roots are Real and Equal, They are :", end=" ")
    print(-b/(2*a))
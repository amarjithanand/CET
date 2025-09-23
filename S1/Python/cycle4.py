a,b = input("Enter two numbers : ").split()
a,b =int(a),int(b)
op = input("Enter the operation to be performed : ( + , - , * , / )")
if op in ['+','-','*','/']:
    if op=='+':
        print(a+b)
    elif op == '-':
        print(a-b)
    elif op == '*':
        print(a*b)
    else:
        if b!=0:
            print(a/b)
        else:
            print("DivisonByZeroException : / Zero is not possible ")
else:
    print("Enter a valid operation")

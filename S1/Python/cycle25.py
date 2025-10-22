class Time:
    def display(self,*args):
        if len(args)==3:
            print(f"{args[0]} hours {args[1]} minutes {args[2]} seconds")
        elif len(args)==6:
            print(f"{args[0]} hours {args[1]} minutes {args[2]} seconds\n{args[3]} day {args[4]} month {args[5]} year")
    
ob1 = Time()
ob1.display(10,20,25)
ob1.display(10,20,30,45,40,3023)
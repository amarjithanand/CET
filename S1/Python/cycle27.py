class Time:
    def __init__(self,hours,minute,second):
        self.hours = hours
        self.minute = minute
        self.second = second
    def display(self):
        print(f"Hours : {self.hours}")
        print(f"Minutes : {self.minute}")
        print(f"Seconds : {self.second}")

    def __add__(self,time2):
        hour = self.hours + time2.hours
        minute = self.minute+time2.minute
        second = self.second + time2.second

        if second>=60:
            minute+=1
            second%=60
        if minute>=60:
            hour+=1
            minute%=60
        if hour>=24:
            hour%=24

        t3 = Time(hour,minute,second)
        return t3
    
t1 = Time(23,60,59)
t1.display()
    
t2 = Time(0,0,1)
t2.display()

t3 = t1+t2
t3.display()




interface vehicle {
    void wheel();
    void seatCapacity();
    void fuelType();
}

class car implements vehicle{
    public void wheel(){
        System.out.println("The car has 4 wheels");
    }
    public void seatCapacity(){
        System.out.println("The car has maximum capacity of 5 people");
    }
    public void fuelType(){
        System.out.println("The car usually have the fuel type of petrol or diesel or electric");
    }
}



 
class bike implements vehicle{
    public void wheel(){
        System.out.println("The bike has 2 wheels");
    }
    public void seatCapacity(){
        System.out.println("The bike has maximum capacity of 2 people");
    }
    public void fuelType(){
        System.out.println("The bike usually have the fuel type of petrol or diesel or electric");
    }
}

class Main{
    public static void main(String[] args){
        car ob1 = new car();
        bike ob2 = new bike();
        ob1.wheel();
        ob1.seatCapacity();
        ob1.fuelType();
        System.out.println("\n");
        ob2.wheel();
        ob2.seatCapacity();
        ob2.fuelType();
    }
}
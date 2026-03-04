import java.util.*;
class shape {
    void calculateArea(int radius){
        double area = 3.14 *radius*radius;
        System.out.println("Area of circle is "+area);
    }
    void calculateArea(int length, int width){
        int area = length * width;
        System.out.println("Area of rectangle is "+area);
    }
}

class Main{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        shape ob = new shape();
        System.out.println("Select the shape to find area \n 1. Circle \n 2. Rectangle");
        int choice = s.nextInt();
        switch(choice){
            case 1 : 
                System.out.println("Enter the radius of the circle :");
                int radius = s.nextInt();
                ob.calculateArea(radius);
                break;
            case 2 :
                System.out.println("Enter the length and breadth of the rectangle :");
                int length = s.nextInt();
                int breadth = s.nextInt();
                ob.calculateArea(length,breadth);
                break;
                default: break;
        }
    }
}
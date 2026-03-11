package myUtil;
import java.util.Scanner;
public class circle{
    public void area(Scanner sc){
        int radius;
        System.out.println("Enter the radius:");
        radius = sc.nextInt();
        System.out.println("Area = " + (3.14 * radius * radius));
    }

    public void perimetre(Scanner sc){
        int radius;
        System.out.println("Enter the radius:");
        radius = sc.nextInt();
        System.out.println("Perimeter = " + (2 * 3.14 * radius));
    }
}

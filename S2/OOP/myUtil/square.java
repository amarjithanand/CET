
package myUtil;
import java.util.Scanner;
public class square{
    public void area(Scanner sc){
        int side;
        System.out.println("Enter the length of the square:");
        side = sc.nextInt();
        System.out.println("Area = " + (side*side));
    }

    public void perimetre(Scanner sc){
        int side;
        System.out.println("Enter the length of the square:");
        side = sc.nextInt();
        System.out.println("Perimeter = " + (4*side));
    }
}
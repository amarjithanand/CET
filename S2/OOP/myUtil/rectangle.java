package myUtil;
import java.util.Scanner;
public class rectangle{
    public void area(Scanner sc){
        int len, wid;
        System.out.println("Enter the length:");
        len = sc.nextInt();
        System.out.println("Enter the width:");
        wid = sc.nextInt();
        System.out.println("Area = " + (len*wid));
    }

    public void perimetre(Scanner sc){
        int len, wid;
        System.out.println("Enter the length:");
        len = sc.nextInt();
        System.out.println("Enter the width:");
        wid = sc.nextInt();
        System.out.println("Perimeter = " + (2*(len+wid)));
    }
}
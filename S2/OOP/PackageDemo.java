import myUtil.*;
import java.util.Scanner;
public class PackageDemo {
    public static void main(String[] args) {
        System.out.println("MyUtil package imported successfully");
        rectangle rect = new rectangle();
        square sq = new square();
        Scanner sc = new Scanner(System.in);
        System.out.println("Calculating area and perimeter of rectangle:");
        rect.area(sc);
        rect.perimetre(sc);
        System.out.println("Calculating area and perimeter of square:");
        sq.area(sc);
        sq.perimetre(sc);
        sc.close();
    }
}
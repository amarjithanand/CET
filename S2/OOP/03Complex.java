//add two complex numbers
import java.util.*;
class complex{
    int a, b;
    Scanner s = new Scanner(System.in);
    void readComplex(){
        System.out.println("Enter the real part of the complex number :");
        this.a = s.nextInt();
        System.out.println("Enter the imaginary part of the complex number :");
        this.b = s.nextInt();
    }
    void printComplex(){
        System.out.println(this.a +" +i"+ this.b);
    }
    complex addComplex(complex c){
        complex res = new complex();
        res.a = this.a + c.a;
        res.b = this.b + c.b;
        return res;
    }
}

class Main{
    public static void main(String[] args){
        complex ob1 = new complex();
        complex ob2 = new complex();
        complex sum = new complex();
        System.out.println("First Complex Number :");
        ob1.readComplex();
        System.out.println("Second Complex Number :");
        ob2.readComplex();

        System.out.println("First Complex Number :");
        ob1.printComplex();

        System.out.println("Second Complex Number :");
        ob2.printComplex();

        System.out.println("Resultant Complex Number :");
        sum = ob1.addComplex(ob2);
        sum.printComplex();
    }
}
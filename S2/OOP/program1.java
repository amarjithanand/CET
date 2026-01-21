import java.io.*;
import java.util.*;

class product{
	String p_name;
	int p_code,p_price;
	product(String name, int code, int price){
		this.p_code = code;
		this.p_name = name;
		this.p_price = price;
	}
	
	void compare(product ob1, product ob2){
		if(this.p_price<ob1.p_price && this.p_price< ob2.p_price){
			System.out.println(this.p_name);
		}
		else if(ob1.p_price<ob2.p_price){
			System.out.println(ob1.p_name);
		}
		else{
			System.out.println(ob2.p_name);
		}
	}
}
		

class Main{
	public static void main(String args[]){
		int code, price;
		String name;
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the name of first product");
		name = s.nextLine();
		System.out.println("Enter the code of first product");
		code = s.nextInt();
		System.out.println("Enter the price of first product");
		price = s.nextInt();
		product ob = new product(name,code,price);
		System.out.println("Enter the name of second product");
		name = s.nextLine();
		System.out.println("Enter the code of second product");
		code = s.nextInt();
		System.out.println("Enter the price of second product");
		price = s.nextInt();
		product ob1 = new product(name,code,price);
		System.out.println("Enter the name of third product");
		name = s.nextLine();
		System.out.println("Enter the code of third product");




		code = s.nextInt();
		System.out.println("Enter the price of third product");
		price = s.nextInt();
		product ob2 = new product(name,code,price);
		ob.compare(ob1,ob2);
	}
}
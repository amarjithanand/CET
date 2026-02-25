class A{
    int a = 10;
    void display(){
        System.out.println("Value of A = "+a);
    }
}
class B extends A
{
    void print(){
        System.out.println("Value of A = "+ super.a);
    }
}
class Main{
    public static void main(String[] args){
        B ob = new B();
        ob.display();
        ob.print();
    }
}
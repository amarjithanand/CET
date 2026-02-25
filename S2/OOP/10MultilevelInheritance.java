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
class C extends B
{
    void call(){
        super.print();
    }
}
class Main{
    public static void main(String[] args){
        C ob = new C();
        ob.display();
        ob.call();
    }
}
class constructor{
    int a,b;
    constructor(){
        a = 0;
        b = 0;
    }    
    constructor(int a,int b){
        this.a = a;
        this.b = b;
    }
    void display(){
        System.out.println("A = "+a);
        System.out.println("B = "+b);
    }
}
class Main{
    public static void main(String[] args){
        constructor ob = new constructor();
        constructor ob1 = new constructor(10, 20);
        ob.display();
        ob1.display();
    }
}
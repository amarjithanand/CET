import java.util.Scanner;

interface shape{
    void area(Scanner sc);
    void perimetre(Scanner sc);
}

class square implements shape{
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

class rectangle implements shape{
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

class circle implements shape{
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

class interfaceDemo{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        square sq = new square();
        circle ci = new circle();
        rectangle re = new rectangle();

        int ch;

        while(true){
            System.out.println("\nMenu:");
            System.out.println("1. Square");
            System.out.println("2. Circle");
            System.out.println("3. Rectangle");
            System.out.println("4. Exit");

            ch = sc.nextInt();

            switch(ch){
                case 1:
                    sq.area(sc);
                    sq.perimetre(sc);
                    break;

                case 2:
                    ci.area(sc);
                    ci.perimetre(sc);
                    break;

                case 3:
                    re.area(sc);
                    re.perimetre(sc);
                    break;

                case 4:
                    System.out.println("Exiting program...");
                    sc.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid choice");
            }
        }
    }
}
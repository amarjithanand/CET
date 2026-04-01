// 6. Define 2 classes; one for generating Fibonacci numbers and other for displaying even numbers in a given range. Implement using threads. (Runnable Interface)

class Even {
    
    public static void main(String[] args) {

        // Child thread
        Fibonacci  fib = new Fibonacci();
        Thread t = new Thread(fib);
        t.start();

        // Even numbers in a given range
        int start = 15;
        int end = 30;
        System.out.println("Even numbers between " + start + " and " + end + ":");
        for (int i = start; i < end; i++) {
            if (i % 2 == 0) {
                System.out.println(i);
            }
        }

    }

}

class Fibonacci implements Runnable {

    // First 10 Fibonacci numbers
    public void run() {
        int n1 = 0, n2 = 1, n3;
        System.out.println("Fibonacci Series:");
        for (int i = 1; i <= 10; i++) {
            System.out.println(n1 + " ");
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
    }

}
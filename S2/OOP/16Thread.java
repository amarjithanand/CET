// 5. Define 2 classes; one for generating multiplication table of 5 and other for displaying first N prime numbers. Implement using threads. (Thread class)


class MultiplicationTable {

    public static void main(String[] args) {

        // Child Thread
        Prime p = new Prime(10);
        p.start();

        // Generate the multiplication table of 5: Main Thread
        System.out.println("Multiplication Table for 5: ");
        for (int i = 0; i < 10; i++)
            System.out.println(5 + " x " + i + " = " + (i * 5));

    }

}

class Prime extends Thread {

    int n;

    Prime(int n) {
        this.n = n;
    }

    // Check whether a number is prime
    static boolean isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    // Print first n prime numbers
    public void run() {
        System.out.println("The first " + n + " prime numbers are: ");
        int count = 0, i = 0;
        while (count < n) {
            if (isPrime(i)) {
                System.out.print(i + " ");
                count++;
            }
            i++;
        }
        System.out.println();
    }
}
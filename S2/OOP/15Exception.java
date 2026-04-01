

import java.util.Scanner;

class Average {
    
    public static void main(String[] args) {
    
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter the positive integers: ");
        int sum = 0;
        for (int i = 0; i < n; i++) {
            try {
                System.out.print("arr[" + i + "]: ");
                arr[i] = readPostiveInteger(sc);
                sum += arr[i];
            } catch (NegativeIntegerException e) {
                e.printStackTrace();
                i--;
            }
        }
        float avg = (float) sum / n;
        System.out.println("Average: " + avg);
        sc.close();
        
    }

    static int readPostiveInteger(Scanner sc) {
        int n = sc.nextInt();
        if (n < 0) {
            throw new NegativeIntegerException();
        }
        return n;
    }

}


class NegativeIntegerException extends RuntimeException {

    NegativeIntegerException() {
        super("Negative Integer!");
    }

}
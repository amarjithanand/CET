import java.util.*;
public class CPU {
    Scanner s = new Scanner(System.in);
    int price,cores,memory;
    String manufacter, ramManufacter;
    class processor{
        processor(int cores, String manufacter){
            return;
        }
        int cores;
        String manufacter;
    }
    class RAM{
        int memory;
        String manufacter;
        RAM(int memory, String ramManufacter){
            this.memory = memory;
            this.manufacter = ramManufacter;
        }
    }
        CPU(int price,int cores, String manufacter, int memory, String ramManufacturer){
        this.price = price;
        processor p= new processor(cores,manufacter);
        RAM r = new RAM(memory, ramManufacturer);
    }
    void readValues(){
        System.out.println("Enter the price of the CPU :");
        this.price = s.nextInt();
        System.out.println("Enter the Number of cores in the CPU :");
        this.cores = s.nextInt();
        System.out.println("Enter the manufacter of the Processor :");
        this.manufacter = s.nextLine();
        System.out.println("Enter the manufacter of the RAM :");
        this.ramManufacter = s.nextLine();
        System.out.println("Enter the memory of the RAM :");
        this.memory = s.nextInt();

    }
}

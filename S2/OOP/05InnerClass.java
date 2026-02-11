import java.util.*;

class CPU {

    Scanner s = new Scanner(System.in);
    int price;

    processor p;
    RAM r;

    class processor {
        int cores;
        String manufacter;

        processor(int cores, String manufacter) {
            this.cores = cores;
            this.manufacter = manufacter;
        }
    }

    static class RAM {
        int memory;
        String manufacter;

        RAM(int memory, String manufacter) {
            this.memory = memory;
            this.manufacter = manufacter;
        }
    }

    CPU(int price, int cores, String manufacter, int memory, String ramManufacturer) {
        this.price = price;
        p = new processor(cores, manufacter);
        r = new RAM(memory, ramManufacturer);
    }

    void display() {
        System.out.println("CPU Price : " + price);
        System.out.println("Processor Cores : " + p.cores);
        System.out.println("Processor Manufacturer : " + p.manufacter);
        System.out.println("RAM Memory : " + r.memory);
        System.out.println("RAM Manufacturer : " + r.manufacter);
    }

    public static void main(String[] args) {

        CPU ob= new CPU(50000, 8, "Intel", 16, "Corsair");
        ob.display();
    }
}
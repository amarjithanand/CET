
import java.io.*;
import java.util.*;
public class fileHandling {

    void createFile(){
         try{
            File obj = new File("myFile.txt");
            if(obj.createNewFile()){
                System.out.println("The file has created succesfully");
            }
            else{
                System.out.println("The file already exists");
            }
        }
        catch(Exception e){
            System.out.println("An error occured"+e);
        }
    }
    void writeFile(){
        try{
            FileWriter w = new FileWriter("myFile.txt");
            w.write("Line 1");
            w.close();
            System.out.println("Successfully wrote to the file");
        }
        catch(Exception e){
            System.out.println("An error occured"+e);
        }
    }
    void readFile(){
        try{
            File obj = new File("myFile.txt");
            Scanner sc = new Scanner(obj);
            while(sc.hasNextLine()){
                String line = sc.nextLine();
                System.out.println(line);
            }
        }
        catch(Exception e){
            System.out.println("An error occured"+e);
        }
    }
    void copyFile(){
        try{
            File obj = new File("myFile.txt");
            FileWriter w = new FileWriter("copyFile.txt");
            Scanner sc = new Scanner(obj);
            while(sc.hasNextLine()){
                w.write(sc.nextLine());
            }
            sc.close();
            w.close();
            
        }
        catch(Exception e){
            System.out.println("An error occured"+e);
        }
    }
    public static void main(String args[]){
        fileHandling fh = new fileHandling();
        fh.createFile();
        fh.writeFile();
        fh.readFile();
        fh.copyFile();
    }
}

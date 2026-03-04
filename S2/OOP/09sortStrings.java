import java.util.*;
class sortStrings{
    public static void main(String args[]){
        String[] fruits = {"Cherry", "Mango", "Apple","Banana","Jack Fruit","Papaya","Orange"};
        Arrays.sort(fruits);
        for(int i = 0; i < fruits.length;i++){
            System.out.println(fruits[i]);
        }
    }
}
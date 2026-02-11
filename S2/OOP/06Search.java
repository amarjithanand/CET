import java.io.*;
import java.util.*;
class search {
    int arr[], key,n;
    Scanner s = new Scanner(System.in);
    void insertArray(){
        System.out.println("Enter the size of the array :");
        n = s.nextInt();
        arr = new int[n];
        System.out.println("Enter the array elements : ");
        for(int i=0;i<n;i++){
            arr[i]  = s.nextInt();
        }
        System.out.println("Enter the element to be searched :");
        key = s.nextInt();
    }
    int searchInArray(){
        for(int i = 0 ; i < n ; i++){
            if(arr[i]==key){
                return i;
            }
        }
        return -1;
    }
}
class Main{
    public static void main(String args[]){
        search ob = new search();    
        ob.insertArray();   
        int n = ob.searchInArray();
        if(n==-1){
            System.out.println("Element not found");
        }
        else{
            System.out.println("Element found at index "+n);
        }
        
    }
}
//Check whether a matrix is symmetric or not
import java.util.*;

class symmetric{
    int n,arr[][];
    Scanner s = new Scanner(System.in);
    void readMatrix(){
        System.out.println("Enter the number of rows in the matrix");
        this.n = s.nextInt();
        arr = new int[n][n];

        System.out.println("Enter the elements in the matrix :");
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n ; j++){
                arr[i][j] = s.nextInt();
            }
        }
    }

    void printMatrix(){
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n ; j++){
                System.out.print(this.arr[i][j]+"\t");
            }
            System.out.println("");
        }
    }

    int compareMatrix(){
        int flag = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n ; j++){
                if(this.arr[i][j]!=this.arr[j][i]){
                    flag++;
                }
            }
        }
        if(flag == 0){
            return 1;
        }
        return 0;
    }
}
class Main{
    public static void main(String args[]){
        int f;
        symmetric ob = new symmetric();
        ob.readMatrix();
        ob.printMatrix();
        f = ob.compareMatrix();
        if(f==1){
            System.out.println("Symmetric!!!");
        }
        else{
            System.out.println("Not - Symmetric!!!");
        }
    }
}
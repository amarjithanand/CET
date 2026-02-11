import java.util.*;

class Matrix{
    static int r,c;
    void readSize(){
        Scanner s = new Scanner (System.in);
        System.out.println("Enter the number of row in matrix ");
        r = s.nextInt();
        System.out.println("Enter the number of columns in matrix ");
        c = s.nextInt();
        
    }
    void readMatrix(int[][] matrix){
        Scanner s = new Scanner (System.in);
       
        for(int i = 0; i < r; i++){
            for(int j = 0 ; j< c; j++){
                matrix[i][j] = s.nextInt();
            }
        }
    }

    void addMatrix(int[][] m1, int[][] m2){
        int res[][] = new int[r][c];
        for(int i = 0; i < r; i++){
            for(int j = 0; j<c; j++){
                res[i][j] = m1[i][j] + m2[i][j];
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j<c; j++){
                System.out.print(res[i][j] + " ");
            }
            System.out.println();
        }
    }
}

class Main{
    public static void main(String[] args){
        Matrix ob =  new Matrix();
        ob.readSize();
        int m1[][] = new int[ob.r][ob.c];
        int m2[][] = new int[ob.r][ob.c];
        ob.readMatrix(m1);
        ob.readMatrix(m2);
        ob.addMatrix(m1,m2);
    }
}
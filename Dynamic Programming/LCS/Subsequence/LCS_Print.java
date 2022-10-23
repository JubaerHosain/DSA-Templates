/**
 * longest common subsequence
 * @author jubaer
 */
import java.util.Scanner;


public class LCS_Print {
    static int[] lcs(int[] a, int[] b){
        int[][] lc = new int[a.length+1][b.length+1];
        
        for(int i = 0; i <= a.length; i++){
            for(int j = 0; j <= b.length; j++){
                if(i == 0 || j == 0){
                    lc[i][j] = 0;
                }
                else if(a[i-1] == b[j-1]){
                    lc[i][j] = 1 + lc[i-1][j-1];
                }
                else{
                    lc[i][j] = Math.max(lc[i-1][j], lc[i][j-1]);
                }
            }
        }
        
        //result array maximum length subsequence
        int size = lc[a.length][b.length];
        int[] result = new int[size];
        
        int i = a.length, j = b.length;
        while(i > 0 && j > 0){
            if(a[i-1] == b[j-1]){
                result[size-1] = a[i-1];
                i--;
                j--;
                size--;
            }
            //go in direction of greater value.
            else if(lc[i][j-1] > lc[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
        
        return result;
    }
    
    public static void main(String args[]){
        Scanner scan =  new Scanner(System.in);
        int[] array1, array2;
        
        int n = scan.nextInt();
        int m = scan.nextInt();
        
        array1 = new int[n];
        array2 = new int[m];
        for(int i = 0; i < n; i++){
            array1[i] = scan.nextInt();
        } 
        
        for(int i = 0; i < m; i++){
            array2[i] = scan.nextInt();
        }
        
        int[] result = lcs(array1, array2);
        for(int i = 0; i < result.length; i++){
            System.out.print(result[i] + " ");
        }
    }
}

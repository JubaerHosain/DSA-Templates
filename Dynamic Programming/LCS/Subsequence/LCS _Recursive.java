/**
 * longest common subsequence
 * @author jubaer
 */
import java.util.Scanner;


public class LCS_Recursion {
    static int lcs(char[] a, char[] b, int i, int j){
        if(i == a.length || j == b.length){
            return 0;
        }
        else if(a[i] == b[j]){
            return 1 + lcs(a, b, i+1, j+1);
        }
        else{
            return Math.max(lcs(a, b, i+1, j), lcs(a, b, i, j+1));
        }
    }
    
    public static void main(String args[]){
        Scanner scan =  new Scanner(System.in);
        
        char[] str1 = scan.next().toCharArray();
        char[] str2 = scan.next().toCharArray();
        
        System.out.println(lcs(str1, str2, 0, 0));
    }
}

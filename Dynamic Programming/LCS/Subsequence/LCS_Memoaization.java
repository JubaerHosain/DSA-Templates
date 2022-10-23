import java.util.Arrays;
import java.util.Scanner;


public class LCS_Memoaization {
    static int lcs(char[] a, char[] b, int i, int j, int[][] dp){
        if(i == a.length || j == b.length){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        else if(a[i] == b[j]){
            return dp[i][j] = 1 + lcs(a, b, i+1, j+1, dp);
        }
        else{
            return dp[i][j] = Math.max(lcs(a, b, i+1, j, dp), lcs(a, b, i, j+1, dp));
        }
    }
    
    public static void main(String args[]){
        Scanner scan =  new Scanner(System.in);
        
        char[] str1 = scan.next().toCharArray();
        char[] str2 = scan.next().toCharArray();
        
        int[][] dp = new int[str1.length][str2.length];
        for(int[] row: dp){
            Arrays.fill(row, -1);
        }
        
        System.out.println(lcs(str1, str2, 0, 0, dp));
    }
}

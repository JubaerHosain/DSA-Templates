import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;


public class LIS {
    private static int lis(int n, int[] arr){
        Integer[] dp = new Integer[n];
        
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        
        return Collections.max(Arrays.asList(dp));
    }
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        
        int n = scan.nextInt();
        int[] arr = new int[n];
        
        for(int i = 0; i < n; i++){
            arr[i] = scan.nextInt();
        }
        
        System.out.println(lis(n, arr));
    }
}

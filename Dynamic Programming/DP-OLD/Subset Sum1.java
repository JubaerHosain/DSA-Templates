

/**
 * using `dynamic programming algorithm
 * @author jubaer
 */
public class SubsetSum {
    private static boolean hasSubset(int[] w, int sum) {
        boolean[][] dp = new boolean[w.length+1][sum+1];
        
        dp[0][0] = true;
        for(int i  = 1; i <= w.length; i++){
            for(int  j = 1; j <= sum; j++){
                if(j-1 == 0){
                    dp[i][j-1] = true;
                }
                
                if(j < w[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-w[i-1]]);
                }
            }
        }
        
        System.out.println("Table: ");
        for(int i = 0; i <= w.length; i++){
            for(int j = 0; j <= sum; j++){
                System.out.print((dp[i][j]? "T":"F") + " ");
            }
            System.out.println();
        }
        
        return dp[w.length][sum];
    }
    
    public static void main(String[] args){
        int[] w = {2,2,3,5,23,12,67,6,20};
        int sum = 50;
        
        System.out.println(hasSubset(w, sum));
    }
}

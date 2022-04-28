class Solution {
    public int coinChange(int[] coins, int amount) {
        if(coins.length == 0){
            return -1;
        }
        
        //each coin has infinite
        //number of times
        
        int[] dp = new int[amount+1];
        Arrays.fill(dp, amount+1);
        dp[0] = 0;
        for(int i = 0; i < coins.length; i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] = Math.min(dp[j], dp[j-coins[i]]+1);
            }
        }
        
        
        return (dp[amount] == amount+1) ? -1:dp[amount];
    }
}
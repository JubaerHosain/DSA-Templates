class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);
        
        int count = 1;
        for(int i = 1; i < nums.length; i++) {
            for(int j = 0; j < i; j++) {
                // <= for longest non-decreasing subseq, non-decreasing means next element is greater or equal. 2 2 3 is valid.
                if(nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], 1+dp[j]);
                    count = Math.max(count, dp[i]);
                }
            }
        }
        
        return count;
    }
}

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for(int i = 0; i < n-1; i++) {
            dp[i][i+1] = __gcd(nums[i], nums[i+1]);
        }
        
        for(int l = 3; l <= n; l++) {
            for(int i = 0; i < n-l+1; i++) {
                int j = i+l-1;
                int gcd = __gcd(nums[i], nums[j]);
                dp[i][j] = __gcd(gcd, dp[i+1][j-1]);
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(dp[i][j] == k)
                    cnt += 1;
            }
        }
        
        return cnt;
    }
};
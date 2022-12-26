using each element only one time.
see subset sum exist or not (linear space)

// https://leetcode.com/problems/number-of-great-partitions/description/

typedef long long ll;
const int mod = 1e9 + 7;

class Solution {
    
public:
    int countPartitions(vector<int>& nums, int k) {
        ll sum = 0;
        for (int a: nums) sum += a;

        if(sum < 2*k) 
            return 0;

        // using each element at most one time.
        
         // number of ways sum less than 
         // dp[i] = total number of ways to make sum i
        vector<ll> dp(k, 0);   
        int n = nums.size();
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
        // reverse loop for picking at most one time
            for(int j = k-1; j >= nums[i]; j--)
                dp[j] = (dp[j] + dp[j-nums[i]])%mod;
        }

        ll total = 1;
        for(int i= 0; i < n; i++) 
            total = (total*2)%mod;

        ll sub = 0;
        for(int i = 0; i < k; i++)
            sub = (sub + dp[i])%mod;

        int ans = (total - 2*sub + mod)%mod;
        return ans;
    }
};





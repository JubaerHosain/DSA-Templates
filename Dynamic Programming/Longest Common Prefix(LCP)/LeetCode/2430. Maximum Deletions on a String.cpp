class Solution {
public:
    int deleteString(string s) {
        int n = s.length();
        
        // longest common prefix starting at s[i] and s[j]
        vector<vector<int>> lcp(n+1, vector<int>(n+1, 0));
        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(s[i] == s[j])
                    lcp[i][j] = 1 + lcp[i+1][j+1];
            }
        }
        
        // max operation starting at i
        vector<int> dp(n, 1);
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(lcp[i][j] >= (j-i))
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        
        return dp[0];
    }
};



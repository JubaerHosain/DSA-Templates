class Solution { 
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int **dp = new int*[n];
        for(int i = 0; i < n; i++)
            dp[i] = new int[n];
        
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int i = 0; i < n-1; i++) {
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else
                dp[i][i+1] = 1;
        }
        
        for(int l = 3; l <= n; l++) {
            for(int i = 0; i < n-l+1; i++) {
                int j = i + l - 1;
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        
        return dp[0][n-1];
    }
};

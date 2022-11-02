class Solution {
    int recur(int curr_d, int d, int start, vector<int> &job_dif, vector<vector<int>> &dp) {
        if(curr_d == d-1) {
            int mx = 0;
            for(int i = start; i < job_dif.size(); i++)
                mx = max(mx, job_dif[i]);
            return mx;
        }
        
        if(dp[curr_d][start] != -1)
            return dp[curr_d][start];
        
        int leftmx = 0;
        int ans = 1e9;
        int left_d = d - curr_d - 1;
        for(int i = start; i < job_dif.size()-left_d; i++) {
            leftmx = max(leftmx, job_dif[i]);
            ans = min(ans, leftmx + recur(curr_d+1, d, i+1, job_dif, dp));
        }
        
        return dp[curr_d][start] = ans;
    }
    
public:
    int minDifficulty(vector<int>& job_dif, int d) {
        if(d > job_dif.size())
            return -1;
        
        int n = job_dif.size();
        
        // dp[i][j] = i'th day started from j
        vector<vector<int>> dp(d, vector<int>(n, -1));
        
        return recur(0, d, 0, job_dif, dp);
    }
};


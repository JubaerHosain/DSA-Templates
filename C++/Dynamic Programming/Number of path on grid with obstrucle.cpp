//grid[i][j] = 0, 1, -1;
//-1 obstrucle
//maximum 1 of right/down path


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int ** dp = new int*[n];
        for(int i = 0; i < n; i++) 
            dp[i] = new int[n];
        
        if(grid[0][0] == -1) 
            return 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = -1;
        
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            if(grid[i][0] != -1) 
                dp[i][0] = dp[i-1][0] + grid[i][0];
            else
                break;
        }
        
        for(int i = 1; i < n; i++) {
            if(grid[0][i] != -1) 
                dp[0][i] = dp[0][i-1] + grid[0][i];
            else
                break;
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < n; j++) {
                if(grid[i][j] == -1)
                    continue;
                else if(dp[i-1][j] == -1 && dp[i][j-1] == -1)
                    continue;
                else if(dp[i-1][j] == -1) 
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                else if(dp[i][j-1] == -1)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[n-1][n-1];
    }
};

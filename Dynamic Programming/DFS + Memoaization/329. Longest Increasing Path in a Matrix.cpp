class Solution {
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; 
    
    bool valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    int get_max(int x, int y, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        if(memo[x][y] != 0)
            return memo[x][y];
        
        int mx = 0;
        memo[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int a = x + dir[i][0];
            int b = y + dir[i][1];
            if(valid(a, b, m, n) && matrix[x][y] < matrix[a][b]) 
                mx = max(mx, get_max(a, b, m, n, matrix, memo));
        }

        return memo[x][y] = 1 + mx;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int mx = 1;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mx = max(mx, get_max(i, j, m, n, matrix, memo));
            }
        }
        
        return mx;
    }
};


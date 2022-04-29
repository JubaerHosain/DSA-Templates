class Solution {
    // check if it is possible to go from (0, 0) to 
    // (n-1, m-1) using only edges of ≤ k cost.
    
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool validIndex(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    bool hasPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> used(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        used[0][0] = true;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int x = dir[i][0] + it.first;
                int y = dir[i][1] + it.second;
                if(validIndex(x, y, m, n)) {
                    if(!used[x][y] && abs(grid[it.first][it.second]-grid[x][y]) <= k) {
                        used[x][y] = true;
                        q.push({x, y});
                    } 
                }
            }
        }
        
        return used[m-1][n-1];
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0, high = 1e6, ans = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(hasPath(heights, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
class Solution {
    int m = 0, n = 0;
    int ans = 0, empty = 0;
    pair<int, int> start, end;
    vector<vector<int>> grid;
    vector<vector<bool>> used;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //{D, U, R, L}
    
    bool valid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    void backtracking(int i, int j, int cnt) {
        if(!valid(i, j) || grid[i][j] == -1)
            return;
        
        if(i == end.first && j == end.second) {
            if(cnt == empty+1)
                ans += 1;
            return;
        }
        
        used[i][j] = true;
        for(int k = 0; k < 4; k++) {
            int x = i + dir[k][0];
            int y = j + dir[k][1];
            if(valid(x, y) && !used[x][y]) {
                backtracking(x, y, cnt + 1);
                // this is backtracking
                used[x][y] = false;
            }
        }
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& vii) {
        grid = vii;
        m = grid.size();
        n = grid[0].size();
        
        used = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) 
                    start = {i, j};
                else if(grid[i][j] == 2)
                    end = {i, j};
                else if(grid[i][j] == 0)
                    empty += 1;
            }
        }
        
        backtracking(start.first, start.second, 0);
        
        return ans;
    }
};



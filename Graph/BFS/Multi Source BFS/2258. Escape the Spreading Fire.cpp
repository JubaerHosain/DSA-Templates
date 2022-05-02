class Solution {
    vector<vector<int>> fire_level;
    vector<vector<int>> people_level;
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
    void fire_bfs(vector<pair<int, int>> &fires, vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> q;
        for(pair<int, int> it: fires) {
            fire_level[it.first][it.second] = 0;
            q.push({it.first, it.second});
        }
        
        while(!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = u.first + dir[i][0];
                int y = u.second + dir[i][1];
                if(valid(x, y, m, n) && fire_level[x][y] == INT_MAX && grid[x][y] == 0) {
                    q.push({x, y});
                    fire_level[x][y] = 1 + fire_level[u.first][u.second];
                }
            }
        }
    }
    
    bool people_bfs(vector<vector<int>> &grid, int time) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                people_level[i][j] = INT_MAX;
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        people_level[0][0] = time;
        
        while(!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = u.first + dir[i][0];
                int y = u.second + dir[i][1];
                if(!valid(x, y, m, n) || grid[x][y] != 0) continue;
                if(people_level[x][y] == INT_MAX && people_level[u.first][u.second]+1 < fire_level[x][y]) {
                    q.push({x, y});
                    people_level[x][y] = 1 + people_level[u.first][u.second];
                }
                if(x == m-1 && y == n-1 && people_level[x][y] == INT_MAX && people_level[u.first][u.second]+1 <= fire_level[x][y]) {
                    q.push({x, y});
                    people_level[x][y] = 1 + people_level[u.first][u.second];
                }
            }
        }
        
        return people_level[m-1][n-1] != INT_MAX;
    }
    
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 1 && n == 1)
            return 1000000000;
        
        fire_level = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        people_level = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        
        vector<pair<int, int>> fires;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) 
                if(grid[i][j] == 1) fires.push_back({i, j});
        }
        
        fire_bfs(fires, grid);
        people_bfs(grid, 0);
        
        if(fire_level[m-1][n-1] == INT_MAX && people_level[m-1][n-1] != INT_MAX)
            return 1000000000;
        
        int ans = -1;
        int low = 0, high = m*n+1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(people_bfs(grid, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};















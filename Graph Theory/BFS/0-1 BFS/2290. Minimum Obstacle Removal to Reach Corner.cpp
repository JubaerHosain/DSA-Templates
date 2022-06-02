class Solution {
private:
    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    bool valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dque;
        dque.push_back({0, 0});
        dist[0][0] = grid[0][0];
        
        while(!dque.empty()) {
            int x = dque.front().first;
            int y = dque.front().second;
            dque.pop_front();
            
            for(int i = 0; i < 4; i++) {
                int a = dir[i][0] + x;
                int b = dir[i][1] + y;
                if(valid(a, b, m, n) && dist[x][y] + grid[a][b] < dist[a][b]) {
                    if(a == m-1 && b == n-1)
                        return dist[x][y] + grid[a][b];
                    
                    dist[a][b] = dist[x][y] + grid[a][b];
                    if(grid[a][b] == 0) 
                        dque.push_front({a, b});
                    else 
                        dque.push_back({a, b});
                }
            }
        }
        
        return 0;
    }
};


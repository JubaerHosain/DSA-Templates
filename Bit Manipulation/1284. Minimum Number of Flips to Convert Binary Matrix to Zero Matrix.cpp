class Solution {
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //{D, U, R, L}
    
    bool valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n; 
    }
    
    void flip(vector<vector<int>> &matrix, int x, int y) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        matrix[x][y] = matrix[x][y] == 0 ? 1 : 0;
        
        for(int i = 0; i < 4; i++) {
            int a = x + dir[i][0];
            int b = y + dir[i][1];
            if(valid(a, b, m, n)) 
                matrix[a][b] = matrix[a][b] == 0 ? 1 : 0;
        }
    }
    
    bool all_zero(vector<vector<int>> &matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == 1) return false;
        }
        return true;
    }
    
    int possible(vector<vector<int>> matrix, vector<pair<int, int>> &array, int num) {
        int n = array.size();
        int bitcnt = 0;
        for(int i = 0; i < n; i++) {
            if(num & (1<<i)) {
                bitcnt += 1;
                flip(matrix, array[i].first, array[i].second);
            }
        }
        return all_zero(matrix) ? bitcnt : INT_MAX;
    }
    
public:
    int minFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int N = m*n;
        vector<pair<int, int>> array;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                array.push_back({i, j});
        }
        
        int ans = INT_MAX;
        for(int num = 0; num < pow(2, N); num++) {
            int cnt = possible(matrix, array, num);
            ans = min(ans, cnt);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
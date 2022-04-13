class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        
        // 0 = move right
        // 1 = move down
        // 2 = move left
        // 3 = move up
        int dir = 0;
        
        int num = 0;
        while(top <= down && left <= right) {
            if(dir == 0) {
                for(int i = left; i <= right; i++)
                    matrix[top][i] = ++num;
                top += 1;
            }
            else if(dir == 1) {
                for(int i = top; i <= down; i++) 
                    matrix[i][right] = ++num;
                right -= 1;
            }
            else if(dir == 2) {
                for(int i = right; i >= left; i--)
                    matrix[down][i] = ++num;
                down -= 1;
            }
            else if(dir == 3) {
                for(int i = down; i >= top; i--)
                    matrix[i][left] = ++num;
                left += 1;
            }
            dir = (dir+1)%4;
        }
        
        return matrix;
    }
};

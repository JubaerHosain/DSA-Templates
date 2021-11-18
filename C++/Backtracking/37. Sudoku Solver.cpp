// previous submission was tle...
// bcz i was traversing again after first completion....

class Solution {    
    bool is_valid(vector<vector<char>>& board, int x, int y, char val) {
        int n = board.size();
        
        // check row 
        for(int j = 0; j < n; j++) {
            if(board[x][j] == val)
                return false;
        }
        
        // check col 
        for(int i = 0; i < n; i++) {
            if(board[i][y] == val)
                return false;
        }
        
        // find top left corner of that subgrid 
        int tx = 3 * (x/3);
        int ty = 3 * (y/3);
        
        // check subgrid
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[tx+i][ty+j] == val)
                    return false;
            }
        }
        
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board, int x, int y) {
        if(x == board.size()) {
            return true;
        }
        
        // calculate next position 
        int nx, ny;
        if(y == board.size()-1) {
            nx = x + 1;
            ny = 0;
        } 
        else {
            nx = x;
            ny = y + 1;
        }
        
        if(board[x][y] != '.') {
           return solveSudoku(board, nx, ny);
        } 
        else {
            for(char val = '1'; val <= '9'; val++) {
                if(is_valid(board, x, y, val)) {
                    board[x][y] = val;
                    
                    if(solveSudoku(board, nx, ny)) 
                        return true;
                    // this is backtracking 
                    // restore the value if condition is not fulfilled
                    board[x][y] = '.';
                }
            }
        }
        
        return false;
    }
    
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
        
        // update value of board internally..
    }
};

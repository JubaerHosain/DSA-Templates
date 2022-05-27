class Solution {
    vector<vector<string>> ans;
    
    void generate_answer(int** board, int n) {
        vector<string> tmp;
        for(int i = 0; i < n; i++) {
            string row = "";
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1)
                    row += 'Q';
                else 
                    row += '.';
            }
            tmp.push_back(row);
        }
        ans.push_back(tmp);
    }
    
    bool is_safe(int** board, int x, int y, int n) {
        // check colum y
        for(int row = 0; row < x; row++) {
            if(board[row][y] == 1)
                return false;
        }
        
        // check left diogonal
        int row = x, col = y;
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 1)
                return false;
            row--, col--;
        }
        
        // check right diagonal 
        row = x, col = y;
        while(row >= 0 && col < n) {
            if(board[row][col] == 1)
                return false;
            row--, col++;
        }
        
        return true;
    }
    
    
    void n_queen(int** board, int x, int n) {
        if(x == n) {
            generate_answer(board, n);
            return;
        }
        
        for(int y = 0; y < n; y++) {
            if(is_safe(board, x, y, n)) {
                board[x][y] = 1;
                n_queen(board, x+1, n);
                // this is backtracking 
                board[x][y] = 0;
            }
        }
    }
    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        int** board = new int*[n];
        for(int i = 0; i < n; i++)
            board[i] = new int[n];
        
        // make vector<string> instead of board
        // then added to the answer would take less time and memory
        
        n_queen(board, 0, n);
        
        return ans;
    }
};












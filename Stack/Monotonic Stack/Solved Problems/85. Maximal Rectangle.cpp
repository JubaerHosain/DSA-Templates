class Solution {
private:
    // NSEL = Next Smaller Element in the Left
    // NSER = Next Smaller Element in the Right
    // implemented using monotonic stack


    // Next smaller element in the left
    vector<int> NSEL(vector<int> &nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> nsel(n);
        for(int i = 0; i < n; i++) {
            while(!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            if(stk.size() == 0)
                nsel[i] = -1;
            else 
                nsel[i] = stk.top();
            stk.push(i);
        }
        return nsel;
    }

    // Next smaller element in the right
    vector<int> NSER(vector<int> &nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> nser(n);
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            if(stk.size() == 0)
                nser[i] = n;
            else 
                nser[i] = stk.top();
            stk.push(i);
        }
        return nser;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsel, nser;
        nsel = NSEL(heights);
        nser = NSER(heights);
        
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) 
            ans = max(ans, heights[i] * (nser[i]-nsel[i]-1));
        
        
        return ans;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> grid(m, vector<int>(n));
        
        // consider every row as histogram
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    if(matrix[i][j] == '1')
                        grid[i][j] = 1;
                    else 
                        grid[i][j] = 0;
                } else {
                    if(matrix[i][j] == '1')
                        grid[i][j] = 1 + grid[i-1][j];
                    else 
                        grid[i][j] = 0;
                }
            }
        }
        
        int ans = 0;
        for(auto &row: grid) {
            ans = max(ans, largestRectangleArea(row));
        }
        
        return ans;
    }
};




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
    
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsel, nser;
        nsel = NSEL(heights);
        nser = NSER(heights);
        
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) 
            ans = max(ans, heights[i] * (nser[i]-nsel[i]-1));
        
        
        return ans;
    }
};




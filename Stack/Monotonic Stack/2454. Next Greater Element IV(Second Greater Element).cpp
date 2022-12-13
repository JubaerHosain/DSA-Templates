// this is giving tle on second greater part


class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        
        // next greater
        vector<int> ng(n, -1);
        stack<int> stk;
        for(int i = n-1; i >= 0; i--) {
            while(!stk.empty() && nums[stk.top()] <= nums[i])
                stk.pop();
            if(!stk.empty())
                ng[i] = stk.top();
            stk.push(i);
        }
        
        // next second greater
        vector<int> sg(n, -1);
        for(int i = 0; i < n; i++) {
            if(ng[i] == -1)
                continue;
            int tmp = ng[i]+1;
            while(tmp != -1 && tmp < n && nums[tmp] <= nums[i])
                tmp = ng[tmp];
            if(tmp != -1 && tmp < n)
                sg[i] = nums[tmp];
        }
        
        return sg;
    }
};


// sliding widow work only if monotonically increasing sum

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> pre(n+1);
        
        for(int i = 0; i < n; i++) 
            pre[i+1] = pre[i] + nums[i];
        
        int ans = INT_MAX;
        deque<int> inx;
        for(int i = 0; i <= n; i++) {
            while(!inx.empty() && pre[i] <= pre[inx.back()])
                inx.pop_back();
            while(!inx.empty() && pre[i]-pre[inx.front()] >= k) {
                ans = min(ans, i - inx.front());
                inx.pop_front();
            }
            inx.push_back(i);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
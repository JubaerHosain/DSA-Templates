class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        // stores indices in decreasing order
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            while(!dq.empty() && i-dq.front() >= k)
                dq.pop_front();
            
            dq.push_back(i);
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};

// Can you find sliding window minimum?
// স্লাইডিং রেঞ্জ মিনিমাম কুয়েরি, শাফায়েতের ব্লগ
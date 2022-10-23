typedef long long ll;

class Solution {
    bool possible(vector<int> &tmp, long long target) {
        vector<long long> nums;
        for(int i: tmp) nums.push_back(i);
        
        for(int i = nums.size()-1; i > 0; i--) {
            if(nums[i] > target) {
                nums[i-1] += (nums[i]-target);
            }
        }
        return nums[0] <= target;
    }
    
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans = 1e9 + 7;
        long long high = 1e9, low = 0;
        while(low <= high) {
            long long mid = (low+high)/2;
            if(possible(nums, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};


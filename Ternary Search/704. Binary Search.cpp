class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while(l <= r) {
            int m1 = l + (r-l)/3;
            int m2 = r - (r-l)/3;
            if(nums[m1] == target)
                return m1;
            else if(nums[m2] == target)
                return m2;
            else if(target < nums[m1])
                r = m1 - 1;
            else if(target > nums[m2])
                l = m2 + 1;
            else 
                l = m1 + 1, r = m2 - 1;
        }
        
        return -1;
    }
};
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(), nums.end());
        
        int currMax = 1, currMin = 1;
        for(int a: nums) {
            if(a == 0) {
                currMax = 1, currMin = 1;
                continue;
            }
            int tmp = a*currMax;
            currMax = max({a*currMax, a*currMin, a});
            currMin = min({tmp, a*currMin, a});
            res = max(res, currMax);
        }
        
        return res;
    }
};

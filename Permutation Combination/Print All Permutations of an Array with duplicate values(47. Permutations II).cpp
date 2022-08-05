class Solution {
    void permute(vector<int> &nums, vector<vector<int>> &ans, int i) {
        if(i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        // this number is placed at i before or not
        // if yes, then don't need to place again at i
        set<int> placed;
        for(int j = i; j < nums.size(); j++) {
            if(placed.count(nums[j]))
                continue;
            placed.insert(nums[j]);
            swap(nums[i], nums[j]);
            permute(nums, ans, i+1);
            swap(nums[i], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums, ans, 0);
        return ans;
    }
};
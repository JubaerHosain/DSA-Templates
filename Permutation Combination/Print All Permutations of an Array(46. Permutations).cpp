class Solution {
    void permute(vector<int> nums, vector<int> asf, vector<vector<int>> &ans) {
        if(nums.size() == 0) {
            ans.push_back(asf);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            vector<int> tmp;
            for(int j = 0; j < nums.size(); j++) {
                if(i != j) tmp.push_back(nums[j]);
            }
            asf.push_back(nums[i]);
            permute(tmp, asf, ans);
            asf.pop_back(); // backtrack
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> asf;
        vector<vector<int>> ans;
        permute(nums, asf, ans);
        return ans;
    }
};

// efficient solution=========================================================
// fixing the i th position permute i+1 to n-1 th elements====================
class Solution {
    void permute(vector<int> &nums, vector<vector<int>> &ans, int i) {
        if(i == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            permute(nums, ans, i+1);
            swap(nums[i], nums[j]);
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums, ans, 0);
        return ans;
    }
};
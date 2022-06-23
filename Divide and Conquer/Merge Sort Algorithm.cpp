class Solution {
    int ans = 0;
    
    void merge_sorted(int left, int mid, int right, vector<int> &nums) {
        int inx = 0;
        int i = left, j = mid+1;
        vector<int> tmp(right-left+1);
        while(i <= mid && j <= right) {
            if(nums[i] < nums[j])
                tmp[inx++] = nums[i++];
            else 
                tmp[inx++] = nums[j++];
        }
        
        while(i <= mid)
            tmp[inx++] = nums[i++];
        while(j <= right)
            tmp[inx++] = nums[j++];
        
        i = 0, j = left;
        while(j <= right) 
            nums[j++] = tmp[i++];
    }
    
    void merge_sort(int left, int right, vector<int> &nums) {
        if(left == right)
            return;
        int mid = (left+right) / 2;
        merge_sort(left, mid, nums);
        merge_sort(mid+1, right, nums);
        merge_sorted(left, mid, right, nums);
    }
    
public:
    void merge_sort(vector<int>& nums) {
        merge_sort(0, nums.size()-1, nums);
        for(int i: nums) cout << i << " ";
    }
};

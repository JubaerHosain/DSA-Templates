class Solution {
private:
    vector<int> count;
    
    void merge(vector<int> &nums, vector<int> &inx, int left, int mid, int right) {
        vector<int> tmp_inx(right-left+1);
        int i = left, j = mid+1, k = 0;
        while(i <= mid && j <= right) {
            if(nums[inx[i]] <= nums[inx[j]]) {
                tmp_inx[k++] = inx[j++];
            } else {
                count[inx[i]] += right-j+1;
                tmp_inx[k++] = inx[i++];
            }
        }
        
        while(i <= mid) 
            tmp_inx[k++] = inx[i++];
        while(j <= right)
            tmp_inx[k++] = inx[j++];
        
        for(int l = left; l <= right; l++)
            inx[l] = tmp_inx[l-left];
    }
    
    void sort(vector<int> &nums, vector<int> &inx, int left, int right) {
        if(left >= right)
            return;
        int mid = (left+right)/2;
        sort(nums, inx, left, mid);
        sort(nums, inx, mid+1, right);
        merge(nums, inx, left, mid, right);
    }

    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> inx(n);
        for(int i = 0; i < n; i++)
            inx[i] = i;
        
        count.resize(n, 0);
        sort(nums, inx, 0, n-1);
        
        return count;
    }
};
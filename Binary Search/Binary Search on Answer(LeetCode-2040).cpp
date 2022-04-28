// Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of 
// nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.


class Solution {
    int getMin(long long midval, long long val, vector<int>& nums2) {
        int ans = nums2.size();
        int left = 0, right = nums2.size()-1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            if(val * nums2[mid] <= midval) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return nums2.size() - ans;
    }
    
    int getMax(long long midval, long long val, vector<int>& nums2) {
        int ans = -1;
        int left = 0, right = nums2.size()-1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            if(val * nums2[mid] <= midval) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return ans + 1;
    }
    
    long long lessElements(long long mid, vector<int>& nums1, vector<int>& nums2) {
        long long count = 0;
        
        for(int i = 0; i < nums1.size(); i++) {
            long long val = nums1[i];
            if(val > 0) 
                count += getMax(mid, val, nums2);
            else if(val < 0)
                count += getMin(mid, val, nums2);
            else if(val == 0 && mid >= 0)
                count += nums2.size();
        }
        
        return count;
    }
    
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long ans = -1;
        long long left = -1e10, right = 1e10;
        
        while(left <= right) {
            long long mid = (left + right) / 2;
            long long elements = lessElements(mid, nums1, nums2);
            if(elements >= k) {
                ans = mid;
                right = mid - 1;
            }
            else if(elements < k) {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};

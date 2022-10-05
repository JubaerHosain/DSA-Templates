/**
 * Given Hints:
 * 1. Can you find a different way to describe the second condition?
 * 2. The sum of the number of set bits in (num1 OR num2) and (num1 AND num2) 
 *    is equal to the sum of the number of set bits in num1 and num2.
 */


class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        set<int> st;
        for(int a: nums) 
            st.insert(a);
        
        vector<int> cnts;
        for(int i: st)
            cnts.push_back(__builtin_popcount(i));
        
        sort(cnts.begin(), cnts.end());
        
        long long ans = 0;
        int n = cnts.size();
        int l = 0, r = n - 1;
        while(l < r && l < n) {
            if(cnts[l]+cnts[r] >= k) {
                ans += (2*(r-l));
                r -= 1;
            } else {
                l += 1;
            }
        }
        
        for(int i: cnts) {
            if(i+i >= k)
                ans += 1;
        }
        
        return ans;
    }
};
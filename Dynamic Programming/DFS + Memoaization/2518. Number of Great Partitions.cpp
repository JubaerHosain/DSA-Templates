// gives TLE: Added just for concept


typedef long long ll;
const int mod = 1e9 + 7;

class Solution {
    ll recur(int i, vector<int> &nums, int k, ll curr, ll sum) {
        if(i == nums.size()) 
            return 0;
        else if(sum-curr < k)
            return 0;
        
        ll in = 0, exc = 0;
        ll tmp = curr+nums[i];
        ll ans = 0;
        if(sum-tmp >= k && tmp >= k)
            ans = 1;

        in = recur(i+1, nums, k, tmp, sum);
        exc = recur(i+1, nums, k, curr, sum);
        
        return (ans+in+exc)%mod;
    }
    
public:
    int countPartitions(vector<int>& nums, int k) {
        ll sum = 0;
        for(int a: nums) sum += a;
        
        return recur(0, nums, k, 0, sum);
    }
};

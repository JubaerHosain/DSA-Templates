typedef long long ll;

class Solution {
    ll get_cost(vector<int>& nums, vector<int>& cost, ll target) {
        ll ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            ll diff = abs(nums[i]-target);
            ans += (diff*cost[i]);
        }
        
        return ans;
    }
    
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll ans = 1e18;
        
        ll low = 0, high = 1e6;

        // difference between low and high should greater than 2, 
        // because after that mid1 and mid2 will start repeating
        while((high-low) > 2) {
            ll m1 = low + (high-low)/3;
            ll m2 = high - (high-low)/3;
            
            ll f1 = get_cost(nums, cost, m1);
            ll f2 = get_cost(nums, cost, m2);
            
            ans = min({ans, f1, f2});
            
            if(f1 < f2) 
                high = m2;
            else 
                low = m1;
        }
        
        for(ll i = low; i <= high; i++)
            ans = min(ans, get_cost(nums, cost, i));
        
        return ans;
    }
};
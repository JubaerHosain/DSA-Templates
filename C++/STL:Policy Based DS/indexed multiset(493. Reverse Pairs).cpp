#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, 
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
    
public:
    int reversePairs(vector<int>& nums) {
        ordered_set<pair<double, int>> my_set;
        
        int n = nums.size();
        my_set.insert({nums[n-1], n-1});
        
        int ans = 0;
        for(int i = n-2; i >= 0; i--) {
            double val = (nums[i])/2.0;
            ans += my_set.order_of_key({val, 0}); // number of element strictly less than val
            my_set.insert({nums[i], i});
        }
        
        return ans;
    }
};

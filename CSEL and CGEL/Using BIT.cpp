class Solution {
private:
    // CSEL = Count Smaller Element on the Left
    // CGEL = Count Greater Element on the Left
    vector<int> BIT;
    int mod = 1e9 + 7;
    
    void update(int i, int x, int n) {
        while(i <= n) {
            BIT[i] += x;
            i += (i&-i);
        }
    }
    
    int prefix_sum(int i) {
        int sum = 0;
        while(i > 0) {
            sum += BIT[i];
            i -= (i&-i);
        }
        return sum;
    } 
    
    int CSEL(int i, int n) {
        return prefix_sum(i-1);
    }
    
    int CGEL(int i, int n) {
        return prefix_sum(n) - prefix_sum(i);
    }
    
public:
    int createSortedArray(vector<int>& a) {
        int mx = *max_element(a.begin(), a.end());
        
        BIT.resize(mx+1);
        int ans = 0;
        for(int i = 0; i < a.size(); i++) {
            ans += min(CSEL(a[i], mx), CGEL(a[i], mx));
            update(a[i], 1, mx);
            ans %= mod;
        }
        
        return ans;
    }
};






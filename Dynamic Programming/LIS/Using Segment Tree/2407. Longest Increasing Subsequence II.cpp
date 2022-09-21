class Solution {
    vector<int> tree;
    
    int get_max(int i, int sl, int sr, int l, int r) {
        if(sl >= l && sr <= r)          // total overlap
            return tree[i];
        else if(sr < l || r < sl)       // no overlap;
            return INT_MIN;

        int mid = (sl + sr) / 2;
        return max(get_max(2*i+1, sl, mid, l, r), get_max(2*i+2, mid+1, sr, l, r));
    }

    void update(int i, int sl, int sr, int pos, int val) {
        if(sl == sr) {                           //update in the leaf node of the tree
            tree[i] = val;
            return;
        }

        int mid = (sl + sr) / 2;
        if(pos <= mid) 
            update(2*i+1, sl, mid, pos, val);
        else 
            update(2*i+2, mid+1, sr, pos, val);

        tree[i] = max(tree[2*i+1], tree[2*i+2]);  //update intermediate nodes after returning the value of the leaf node
    }

    int get_max(int l, int r, int n) {
        return get_max(0, 0, n-1, l, r);
    }

    void update(int pos, int val, int n) {
        update(0, 0, n-1, pos, val);
    }
    
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int N = 1e5 + 5;
        tree.resize(4*N);
            
        // Same concept as n^2 LIS dp
        // Following implementation also applicable for general LIS dp problem
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int l = max(0, nums[i]-k);
            int r = nums[i]-1;
            int mx = get_max(l, r, N);
            update(nums[i], 1+mx, N);
        }
        
        return get_max(0, N-1, N);
    }
};




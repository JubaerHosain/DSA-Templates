How to find a index j such that j > i and nums[j] > nums[i] and if there are many possible indices j find the smallest one.

We can use a stack for this problem but it is also possible to do it with a segment tree lets see how, suppose we build our segment tree of max operation.

Now suppose you are in a range of your segment tree represented by [l, r] now first check the maximum value in the left tree i.e [l, mid] if the maximum in the left tree is greater than nums[i] then answer lies in the left tree otherwise answer lies in the right tree i.e [mid + 1, r], so keep going down in the tree until the point l == r and the index j such that nums[i] < nums[j] is l.

So first find the first index such that k such that nums[i] < nums[k] in the range [i + 1, n] using segment tree then find the second index j such that nums[i] < nums[j] in the range [k + 1, n].
And if either k or j is not present the answer for index i is -1.

Time complexity: O(n * log(n))
Space complexity: O(n)

// =============================================================================================

class Solution {
    vector<int> tree;

    // range max tree
    int buildTree(int i, int l, int r, vector<int> &nums) {
        if (l == r) 
            return tree[i] = nums[l];
        int mid = (l + r) / 2;
        return tree[i] = max(buildTree(2*i+1, l, mid, nums), buildTree(2*i+2, mid+1, r, nums));
    }

    int query(int num, int pos, int i, int l, int r, vector<int> &nums) {
        if(tree[i] <= num || r < pos)
            return INT_MAX;
        else if(l == r)
            return l;

        int mid = (l + r) / 2;
        int res = query(num, pos, 2*i+1, l, mid, nums);
        if (res == INT_MAX)
            res = query(num, pos, 2*i+2, mid+1, r, nums);

        return res;
    }

public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        tree.resize(4*n);
        buildTree(0, 0, n-1, nums);

        for (int i = 0; i < n; i++) {
            int ng = query(nums[i], i+1, 0, 0, n-1, nums);
            if(ng != INT_MAX) {
                int sng = query(nums[i], ng+1, 0, 0, n-1, nums);
                cout << sng << " ";
                if(sng != INT_MAX)
                    ans[i] = nums[sng];
            } 
        }

        return ans;
    }
};



1. brute force, n^3 solution, creat an array of each node, then run a n-squred loop 
to chack every pair of node and run a dfs to check equality(this takes another n time).
2. (n^2)longn using hashmap, tree flattaning
3. using map + dfs


class Solution {
private:
    map<string, int> cnt;
    vector<TreeNode*> ans;
    
    string traverse(TreeNode* root) {
        if(root == NULL)
            return "X";
        string left = traverse(root->left);
        string right = traverse(root->right);
        // why added "->" ??
        // for this testcase: [2,1,11,11,null,1]
        string curr = to_string(root->val) + "->" + left + right;
        cnt[curr] += 1;
        if(cnt[curr] == 2)
            ans.push_back(root);
        return curr;
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return ans;
    }
};

class Solution {
    int res = 0;
    vector<int> subtree_sum, ans;
    vector<vector<int>> g;
    
    void dfs0(int u, int p = -1, int d = 0) {
        res += d;
        subtree_sum[u] = 1;
        
        for(int v: g[u]) {
            if(v == p)
                continue;
            dfs0(v, u, 1 + d);
            subtree_sum[u] += subtree_sum[v];
        }
    }
    
    void dfs1(int u, int p = -1) {
        ans[u] = res;
        
        for(int v: g[u]) {
            if(v == p)
                continue;
            
            // re-root to v
            res -= subtree_sum[v];
            subtree_sum[u] -= subtree_sum[v];
            res += subtree_sum[u];
            subtree_sum[v] += subtree_sum[u];
            
            dfs1(v, u);
            
            // restore root to u
            subtree_sum[v] -= subtree_sum[u];
            res -= subtree_sum[u];
            subtree_sum[u] += subtree_sum[v];
            res += subtree_sum[v];
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        subtree_sum.resize(n);
        ans.resize(n);
        g.resize(n);
        
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        dfs0(0);
        dfs1(0);
        
        return ans;
    }
};



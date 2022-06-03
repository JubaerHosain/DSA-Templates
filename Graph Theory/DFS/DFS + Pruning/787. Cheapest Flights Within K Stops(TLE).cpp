class Solution {
private:
    int min_cost = INT_MAX;
    vector<vector<pair<int, int>>> adj;
    
    void dfs(int u, int cost, int dst, int k, vector<bool> &used) {
        // pruning unnecessary paths
        if(k < -1 || cost >= min_cost) 
            return;
        else if(u == dst) 
            min_cost = cost;
        
        used[u] = true;
        for(auto &it: adj[u]) {
            int v = it.first;
            int w = it.second;
            if(!used[v]) {
                dfs(v, w + cost, dst, k-1, used);
            }
        }
        
        // restore value of used
        used[u] = false;
    }
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adj.resize(n);
        
        for(auto &it: flights) 
            adj[it[0]].push_back({it[1], it[2]});
        
        vector<bool> used(n, false); 
        
        dfs(src, 0, dst, k, used);
        
        return min_cost == INT_MAX ? -1 : min_cost;
    }
};





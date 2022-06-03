class Solution {
private:
    vector<vector<pair<int, int>>> adj;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adj.resize(n);
        
        // node, price
        for(auto &it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // pirce, node, hop
        min_heap.push({0, src, k});
        while(!min_heap.empty()) {
            auto it = min_heap.top();
            min_heap.pop();
            int p = it[0];
            int u = it[1];
            int h = it[2];
            
            if(u == dst) return p;
            
            if(h < 0) continue;
            
            for(auto &it: adj[u]) {
                int v = it.first;
                int w = it.second;
                min_heap.push({p + w, v, h-1});
            }
        }
        
        return -1;
    }
};




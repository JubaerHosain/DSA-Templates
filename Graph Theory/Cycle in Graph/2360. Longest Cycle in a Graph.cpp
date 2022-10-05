/**
## Read the problem statement first. (Given graph is a special graph).
Given  Hints: 
1. How many cycles can each node at most be part of?
2. Each node can be part of at most one cycle. Start from each node and 
   find the cycle that it is part of if there is any. Save the already visited 
   nodes to not repeat visiting the same cycle multiple times.
*/

class Solution {
    int mx = -1;
    vector<int> dist;
    vector<bool> on_stack;
    vector<vector<int>> g;
    
    void cycle(int u, int d) {
        dist[u] = d;
        on_stack[u] = true;
        
        for(int v: g[u]) {
            if(dist[v] == -1) 
                cycle(v, d+1);
            else if(on_stack[v])
                mx = max(mx, d-dist[v]+1);
        }
        
        on_stack[u] = false;
    }
    
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        g.resize(n);
        dist.resize(n, -1);
        on_stack.resize(n, false);
        
        for(int i = 0; i < n; i++) {
            if(edges[i] != -1)
                g[i].push_back(edges[i]);
        }
        
        for(int u = 0; u < n; u++) {
            if(dist[u] == -1) {
                cycle(u, 0);
            }
        }
        
        return mx;
    }
};




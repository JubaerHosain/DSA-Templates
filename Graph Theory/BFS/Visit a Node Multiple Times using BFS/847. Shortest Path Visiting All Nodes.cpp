// trick -> visiting a node multiple time using mask
// mask = current state of visited nodes

class Solution {
private:
    int bfs(vector<vector<int>>& graph) {
        int n = graph.size();
        int total = (1<<n) - 1;
        
        // {node, mask}
        set<pair<int, int>> visited;
        
        // {node, {dist, mask}}
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; i++) {
            int mask = (1<<i);
            q.push({i, {0, mask}});
            visited.insert({i, mask});
        }
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int u = front.first;
            int dist = front.second.first;
            int mask = front.second.second;
            for(int v: graph[u]) {
                int tmp_mask = mask | (1<<v);
                if(tmp_mask == total)
                    return dist + 1;
                else if(!visited.count({v, tmp_mask})) {
                    visited.insert({v, tmp_mask});
                    q.push({v, {dist+1, tmp_mask}});
                }
            }
        }
        
        return 0;
    }
    
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1) 
            return 0;
        
        return bfs(graph);
    }
};



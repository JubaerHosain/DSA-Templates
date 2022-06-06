// 787. Cheapest Flights Within K Stops

class Solution { 
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        vector<int> tmp_dist(n, INT_MAX);
        
        // tmp_dist is used for such that at every iteration 
        // add exacly one new level or minimize the cost of existing edges 
        
        dist[src] = tmp_dist[src] = 0;
        for(int i = 1; i <= k+1; i++) {
            for(auto &it: flights) {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                // notice where dist is used ans where tmp_dist
                if(dist[u] != INT_MAX && dist[u] + w < tmp_dist[v]) 
                    tmp_dist[v] = dist[u] + w;
            }
            dist = tmp_dist;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};





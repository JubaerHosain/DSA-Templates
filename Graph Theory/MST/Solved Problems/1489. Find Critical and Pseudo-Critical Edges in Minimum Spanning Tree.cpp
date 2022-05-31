class Solution {
private:
    vector<int> prnt, rnk;

    int find(int u) {
        if(prnt[u] == -1) return u;
        return prnt[u] = find(prnt[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);

        if(rnk[u] < rnk[v]) swap(u, v);

        rnk[u] += rnk[v];
        prnt[v] = u;
    }
    
    int mst(vector<vector<int>>& edges, vector<int> included, vector<int> excluded) {
        for(int i = 0; i < prnt.size(); i++) {
            prnt[i] = -1;
            rnk[i] = 1;
        }
        
        int cost = 0;
        if(included.size() > 0) {
            merge(included[0], included[1]);
            cost += included[2];
        }
        
        for(vector<int> edge: edges) {
            if(excluded.size() == edge.size() && excluded[3] == edge[3])
                continue;
            else if(find(edge[0]) != find(edge[1])) {
                merge(edge[0], edge[1]);
                cost += edge[2];
            }
        }
        
        return rnk[find(0)] == prnt.size() ? cost : INT_MAX;
    }

    
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        rnk = vector<int>(n, 1);
        prnt = vector<int>(n, -1);
        
        
        // add index of i'th edge
        // {u, v, weight, i}
        for(int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        
        // sort non-decreasing order of weight
        sort(edges.begin(), edges.end(), cmp);
        
        int min_cost = mst(edges, vector<int>(), vector<int>());
        
        vector<int> critical, psudo;
        for(vector<int> edge: edges) {
            // excluding edge
            int ex_cost = mst(edges, vector<int>(), edge);
            if(ex_cost > min_cost) {
                critical.push_back(edge[3]);
            } else if(ex_cost == min_cost) {
                // included edge
                int in_cost = mst(edges, edge, vector<int>());
                if(in_cost == ex_cost) 
                    psudo.push_back(edge[3]);
            }
        }
        
        return {critical, psudo};
    }
};



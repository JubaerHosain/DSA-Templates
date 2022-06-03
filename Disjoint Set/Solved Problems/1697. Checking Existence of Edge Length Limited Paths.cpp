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
        
        if(u == v)
            return;

        if(rnk[u] < rnk[v]) swap(u, v);

        rnk[u] += rnk[v];
        prnt[v] = u;
    }
    
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    }
    
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        rnk = vector<int>(n, 1);
        prnt = vector<int>(n, -1);
        
        sort(edges.begin(), edges.end(), cmp);
        
        // add position to end
        // {u, v, limit, position}
        for(int i = 0; i < queries.size(); i++) 
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), cmp);
        
        int inx = 0;
        vector<bool> ans(queries.size(), false);
        for(auto &it: queries) {
            while(inx < edges.size() && edges[inx][2] < it[2]) {
                merge(edges[inx][0], edges[inx][1]);
                inx += 1;
            }
            if(find(it[0]) == find(it[1]))
                ans[it[3]] = true;
        }
        
        return ans;
    }
};


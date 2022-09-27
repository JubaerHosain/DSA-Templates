class Solution {
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
    
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        map<int, vector<int>> mp;
        vector<vector<int>> g(n);
        
        for(int i = 0; i < n; i++)
            mp[vals[i]].push_back(i);
        
        for(auto &it: edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        int good_path = n;
        
        // initialize dsu
        rnk = vector<int>(n, 1);
        prnt = vector<int>(n, -1);
        
        // make groups for lower values first
        // map contains keys in ascending order
        for(auto &[key, nodes]: mp) {
            for(int u: nodes) {
                for(int v: g[u]) {
                    if(vals[v] <= vals[u])
                        merge(u, v);
                }
            }
            
            map<int, int> cnt;
            for(int u: nodes) 
                cnt[find(u)] += 1;
            
            for(auto &[key, sz]: cnt)
                good_path += (sz*(sz-1)/2);
        }
        
        return good_path;
    }
};





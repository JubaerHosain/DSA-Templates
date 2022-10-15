class Solution {
    int d = 1;
    vector<vector<int>> g;
    
    pair<int, char> dfs(int u, const string &s) {
        int mx1 = 0, mx2 = 0;

        for(int v: g[u]) {
            pair<int, char> cnt = dfs(v, s);
            if(cnt.second != s[u]) {
                if(cnt.first > mx1) {
                    mx2 = mx1;
                    mx1 = cnt.first;
                } else if(cnt.first > mx2) {
                    mx2 = cnt.first;
                }
            }
        }
        
        d = max(d, 1 + mx1 + mx2);
        
        return {1 + mx1, s[u]};
    }
    
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.length();
        
        g.resize(n);
        for(int i = 1; i < n; i++) 
            g[parent[i]].push_back(i);
        
        dfs(0, s);
        
        return d;
    }
};


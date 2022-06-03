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

public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        rnk = vector<int>(n, 1);
        prnt = vector<int>(n, -1);
        
        vector<bool> ans(requests.size());
        for(int i = 0; i < requests.size(); i++) {
            int u = find(requests[i][0]);
            int v = find(requests[i][1]);
            bool flag = true;
            // for(auto it: restrictions) gives tle why?
            // after giving & it's accepted within time
            for(auto& it: restrictions) {
                int a = find(it[0]);
                int b = find(it[1]);
                if((u == a && v == b) || (u == b && v == a)) {
                    flag = false;
                    break;
                }
            }
            ans[i] = flag;
            if(flag) 
                merge(u, v);
        }
        
        return ans;
    }
};


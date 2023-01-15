
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
const int N = 1e5 + 5;
typedef long long ll;

class Solution {
    vector<ll> g[N];
    ll depth[N], ans[N];
    vector<int> price;

    void height(int u, int p) {
        ll mx = price[u];
        for(int v: g[u]) {
            if(v == p) continue;
            height(v, u);
            mx = max(mx, price[u] + depth[v]);
        }
        depth[u] = mx;
    }

    void dfs(int u, int p, ll prnt_max) {
        vector<ll> suffix_max, prefix_max;
        for(int v: g[u]) {
            if(v == p) continue;
            prefix_max.push_back(depth[v]);
            suffix_max.push_back(depth[v]);
        }

        int n = prefix_max.size();
        rep(i, 1, n) prefix_max[i] = max(prefix_max[i], prefix_max[i-1]);
        rrep(i, n-2, 0) suffix_max[i] = max(suffix_max[i], suffix_max[i+1]);

        int i = 0;
        for(int v: g[u]) {
            if(v == p) continue;
            ll left_max = (i == 0) ? 0 : prefix_max[i-1];
            ll right_max = (i == n-1) ? 0 : suffix_max[i+1];
            // in leaf height = 0
            ll parent_max = price[u] + max(prnt_max, max(left_max, right_max));
            dfs(v, u, parent_max);
            i++;
        }

        ans[u] = price[u] + max(prnt_max, n == 0 ? 0 : prefix_max.back());
    }
  
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& _price) {
        price = _price;
        
        for(auto it: edges) {
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }

        height(0, -1);
        dfs(0, -1, -1);

        ll mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, ans[i]-price[i]);
        }
        
        return mx;
    }
};




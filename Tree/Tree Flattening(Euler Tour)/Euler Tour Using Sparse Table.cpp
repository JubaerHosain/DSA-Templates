#include<bits/stdc++.h>
using namespace std;
#define all(v)                  v.begin(), v.end()
#define endl                    '\n'//in interactive problem should not use this
#define print(var)              cout << var << endl
#define out(a, b)               cout << a << " " << b << endl
#define rep(i, s, n)            for(int i = s; i < n; i++)
#define rrep(i, n, s)           for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*************Sparse Table of RMQ*************/
const int N = 1e5+5;
int table[N][30];

void build_table(vector<int> a, int n) {
    rep(i, 0, n) 
        table[i][0] = i;

    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; (i + (1 << j) - 1) < n; i++) {
            if(a[table[i][j-1]] < a[table[i+(1<<(j-1))][j-1]]) 
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i+(1<<(j-1))][j-1];
        }
    }
}

int get_min(int l, int r, vector<int> &a) {
    int j = log2(r-l+1);
    if(a[table[l][j]] < a[table[r-(1<<j)+1][j]]) 
        return table[l][j];
    else
        return table[r-(1<<j)+1][j];
}

/*************Euler tour*************/
vector<int> g[N];
int first_index[N];             //first index of euler path
vector<int> nodes, depth;

void dfs_euler(int u, int p, int d) {
    first_index[u] = depth.size();
    depth.push_back(d);
    nodes.push_back(u);
    for(int v: g[u]) {
        if(v == p) 
            continue;
        dfs_euler(v, u, d+1);
        depth.push_back(d);
        nodes.push_back(u);
    }
}

int dist(int u, int v) {
    int l = first_index[u];
    int r = first_index[v];
    if(l > r) swap(l, r);
    int lca_index = get_min(l, r, depth);
    int d = depth[l] + depth[r] - 2*depth[lca_index];
    return d;
}

/*************User defined function*************/

void solve() {
    int n, m;
    cin >> n >> m;

    depth.resize(0);
    nodes.resize(0);
    rep(i, 1, n+1) g[i].clear();

    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs_euler(1, -1, 0);
    build_table(depth, depth.size());
    
    rep(k, 0, m) {
        int a, b;
        cin >> a >> b;

        ll ans = 0;
        rep(i, 1, n+1) {
            ans += min(dist(i, a), dist(i, b));
        }

        print(ans);
    }
} 

/*************main function*************/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    cout << fixed << showpoint;
    cout << setprecision(16);

    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}    

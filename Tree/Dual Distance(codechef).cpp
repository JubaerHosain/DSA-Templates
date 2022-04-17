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

/*************User defined function*************/
const int N = 1e5+5;
int up[N][20];
vector<int> g[N];
ll sub_size[N], depth[N];
ll tmp_dist_sum[N], dist_sum[N];

//works also for binary lifting
void dfs(int u, int p, int d) {
    depth[u] = d;
    sub_size[u] = 1;
    tmp_dist_sum[u] = d;

    //binary lifting
    up[u][0] = p;
    rep(i, 1, 20) {
        if(up[u][i-1] != -1) 
            up[u][i] = up[up[u][i-1]][i-1];
        else
            up[u][i] = -1;
    }

    for(int v: g[u]) {
        if(v == p) continue;
        dfs(v, u, d+1);
        sub_size[u] += sub_size[v];
        tmp_dist_sum[u] += tmp_dist_sum[v];
    }
}

//calculate all distance sum
void dfs1(int u, int p, int n) {
    dist_sum[u] = dist_sum[p] + n - 2 * sub_size[u];    //simplified equation
    for(int v: g[u]) {
        if(v == p) continue;
        dfs1(v, u, n);
    }
}

//finds lca of two node
int find_lca(int a, int b) {
    if(depth[a] > depth[b])
        swap(a, b);

    int k = depth[b] - depth[a];
    rrep(i, 19, 0) {
        if(k >= (1<<i))  {
            b = up[b][i];
            k -= (1<<i);
        }
    }

    if(a == b)
        return a;

    rrep(i, 19, 0) {
        if(up[a][i] != -1 && (up[a][i] != up[b][i]))
            a = up[a][i], b = up[b][i];
    }

    return up[a][0];
}

int get_ancestor(int node, int k) {
    for(int i = 19; i >= 0; i--) {
        if(k >= (1 << i)) {
            node = up[node][i];
            k -= (1 << i);
        }
    }
    
    return node;
}

ll dist(int a, int b, int n) {
    if(depth[a] < depth[b]) 
        swap(a, b);

    int lca = find_lca(a, b);
    int d = depth[a] + depth[b] - 2*depth[lca];  

    int x = a, y = b;
    if(d > 1) {
        int k = (d-1)/2;
        x = get_ancestor(a, k);
        y = up[x][0];
    }

    ll dx = tmp_dist_sum[x];
    ll dy = dist_sum[y] - dx;

    lca = find_lca(y, a);
    d = depth[y] + depth[a] - 2*depth[lca];
    ll ansA = dist_sum[a] - (dy + d * (n-sub_size[x]));

    lca = find_lca(x, b);
    d = depth[x] + depth[b] - 2*depth[lca];
    ll ansB = dist_sum[b] - (dx + (d-1) * sub_size[x]);

    return ansA + ansB;
}


void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, n+1) g[i].clear();

    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1, 0);
    dist_sum[1] = tmp_dist_sum[1];
    for(int v: g[1]) dfs1(v, 1, n);
    
    rep(k, 0, m) {
        int a, b;
        cin >> a >> b;

        print(dist(a, b, n));
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

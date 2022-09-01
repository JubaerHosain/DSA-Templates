#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
 
/*************User defined function*************/
const int N = 2e5+5;
int depth[N], dist[N];
int up[N][20];

vector<pair<int, pii>> g[N]; // {node, ci, di}
vector<int> col[N]; // {ci-> starti}
vector<pii> color[N]; // ci -> di, -1/1
int start[N];
int timer = 1;

void binary_lifting(int u, int p, int dep) {
    depth[u] = dep;
    up[u][0] = p;
    rep(i, 1, 20) {
        if(up[u][i-1] != -1) 
            up[u][i] = up[up[u][i-1]][i-1];
        else
            up[u][i] = -1;
    }

    for(auto tup: g[u]) {
        int v = tup.first;
        int c = tup.second.first;
        int di = tup.second.second;
        if(v == p) continue;

        dist[v] = dist[u] + di;
        start[v] = timer++;
        col[c].push_back(start[v]);
        color[c].push_back({di, 1});

        binary_lifting(v, u, dep+1);

        col[c].push_back(timer++);
        color[c].push_back({-di, -1});
    }
}

int lca(int a, int b) {
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

void solve() {
    int n, q;
    cin >> n >> q;
 
    rep(i, 1, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        g[a].push_back({b, {c, d}});
        g[b].push_back({a, {c, d}});
    }

    binary_lifting(1, -1, 0);

    // for(int i = 1; i <= n-1; i++) {
    //     for(int j = 0; j < color[i].size(); j++) {
    //         cout << "{" << col[i][j] << " " << color[i][j].first << " " << color[i][j].second << "}, ";
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i <= n-1; i++) {
        if(color[i].size() <= 1) continue;
        for(int j = 1; j < color[i].size(); j++) {
            color[i][j].first += color[i][j-1].first;
            color[i][j].second += color[i][j-1].second;
        }
    }
    
    while(q--) {
        int c, y, u, v;
        cin >> c >> y >> u >> v;

        int LCA = lca(u, v);
        int distance = dist[u] + dist[v] - 2*dist[LCA];

        // cout << LCA << " " << u << " " << v  << " " << endl;

        if(color[c].size() < 1) {
            cout << distance << endl;
            continue;
        }

        int node_cnt = 0;
        int sum = 0;
        if(LCA != u) {
            int l = upper_bound(all(col[c]), start[LCA]) - col[c].begin();
            int r = upper_bound(all(col[c]), start[u]) - col[c].begin() - 1;

            node_cnt += (l == 0 ? color[c][r].second : color[c][r].second - color[c][l-1].second);
            sum += (l == 0 ? color[c][r].first : color[c][r].first - color[c][l-1].first);

        }
        if(LCA != v) {
            int l = upper_bound(all(col[c]), start[LCA]) - col[c].begin();
            int r = upper_bound(all(col[c]), start[v]) - col[c].begin()-1;

            // cout << l << " " << r << " " << start[LCA] << " " << start[v] << endl;
            // cout << color[c][1].second.first << endl;

            node_cnt += (l == 0 ? color[c][r].second : color[c][r].second - color[c][l-1].second);
            sum += (l == 0 ? color[c][r].first : color[c][r].first - color[c][l-1].first);
        }

        // cout << distance << " " << sum << " " << node_cnt << endl;

        distance -= sum;
        distance += node_cnt * y;
        cout << distance << endl;
    }
} 
 
/*************main function*************/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
}

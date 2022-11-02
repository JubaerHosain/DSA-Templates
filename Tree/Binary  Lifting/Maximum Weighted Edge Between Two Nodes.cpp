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
const int LOG = 20;
vector<int> depth(N);
int up[N][LOG], mx[N][LOG];
// {node, weight}
vector<pair<int, int>> g[N];
 
// before comming u, all parent of u is processed
void binary_lifting(int u, int p = 0, int d = 0) {
    up[u][0] = p;
    depth[u] = d;

    for(int i = 1; i < LOG; i++) { 
        up[u][i] = up[up[u][i-1]][i-1];
        mx[u][i] = max(mx[u][i-1], mx[up[u][i-1]][i-1]);
    }
 
    for(auto it: g[u]) {
        int v = it.first;
        int w = it.second;

        if(v == p) 
            continue;

        mx[v][0] = w;

        binary_lifting(v, u, d+1);
    }
}

int get_max(int a, int b) {
    if(depth[a] > depth[b])
        swap(a, b);

    int ans = 0;
    int k = depth[b] - depth[a];
    for(int i = LOG-1; i >= 0; i--) {
        if(k >= (1<<i))  {
            ans = max(ans, mx[b][i]);
            b = up[b][i];
            k -= (1<<i);
        }
    }

    if(a == b)
        return ans;

   for(int i = LOG-1; i >= 0; i--) {
        if(up[a][i] != -1 && (up[a][i] != up[b][i])) {
            ans = max({ans, mx[a][i], mx[b][i]});
            a = up[a][i], b = up[b][i];
        }
    }

    ans = max({ans, mx[a][0], mx[b][0]});

    return ans;
}
 
void solve() {
    // int n, q;
    // cin >> n >> q;
 
    // for(int i = 1; i < n; i++) {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     g[u].push_back({v, w});
    // }
 
    // // 1 based indexing
    // binary_lifting(1);
    
    // while(q--) {
    //     int u, v;
    //     cin >> u >> v;
        
    // }

    // testing
    g[3].push_back({5, 5});
    g[3].push_back({1, 3});
    g[5].push_back({6, 1});
    g[5].push_back({2, 2});
    g[2].push_back({7, 3});
    g[2].push_back({4, 1});
    g[1].push_back({8, 10});
    g[1].push_back({9, 4});

    // rooted in 3
    binary_lifting(3);


    // for(int i = 1; i <= 9; i++) {
    //     for(int j = 0; j <= 5; j++)
    //         cout << mx[i][j] << " ";
    //     cout << endl;
    // }

    for(int i = 1; i <= 9; i++) {
        for(int j = i+1; j <= 9; j++) {
            cout << i << " " << j << " -> " << get_max(i, j) << endl;
        }
    }
} 
 
/*************main function*************/
int main() {
    solve();
 
    return 0;
}

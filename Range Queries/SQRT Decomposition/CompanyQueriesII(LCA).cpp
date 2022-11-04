#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*************User defined function*************/
const int N = 2e5 + 5;
int block_size;

vector<int> g[N];
vector<int> depth(N), parent(N), jump_parent(N);

int get_height(int u, int p = 0) {
    int h = 0;
    for(int v: g[u]) {
        if(v == p)
            continue;
        h = max(h, get_height(v, u));
    }

    return 1 + h;
}

void dfs(int u, int p = 0, int d = 0) {
    depth[u] = d;
    parent[u] = p;

    if(depth[u]%block_size == 0) {
        /* if it is first node of the block
        then its jump_parent is its current parent */
        jump_parent[u] = parent[u];
    } else {
        /* if it is not the first node of this block
        then its jump_parent is jump_parent of its parent */
        jump_parent[u] = jump_parent[p];
    }

    for(int v: g[u]) {
        if(v == p)
            continue;
        dfs(v, u, d+1);
    }
}

void build_sqrt(int height) {
    block_size = sqrt(height);
    dfs(1, 0, 0);
}

int naive_lca(int u, int v) {
    if(u == v) return u;
    if(depth[u] > depth[v])
        swap(u, v);
    v = parent[v];
    return naive_lca(u, v);
}

int get_lca(int u, int v) {
    while(jump_parent[u] != jump_parent[v]) {
        if(depth[u] > depth[v])
            swap(u, v);
        v = jump_parent[v];
    }

    // u and v have same jump_parent
    return naive_lca(u, v);
}

void solve() {
    int n, q;
    cin >> n >> q;

    for(int v = 2; v <= n; v++) {
        int u; cin >> u;
        g[u].push_back(v);
    }

    // 1 rooted tree
    build_sqrt(get_height(1));

    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << get_lca(u, v) << endl;
    }
} 
 
/*************main function*************/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    solve();
 
    return 0;
}

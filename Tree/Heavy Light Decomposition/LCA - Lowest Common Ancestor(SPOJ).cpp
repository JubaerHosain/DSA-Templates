#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 1e3+5;
vector<int> tree[N];
vector<int> depth(N, 0);
vector<int> parent(N, 0);
vector<int> heavy_child(N, 0);
vector<int> subtree_size(N, 0);
vector<int> head(N), index_of(N, 0);
int curr_index = 0;

void dfs1(int u, int p = 0) {
    parent[u] = p;
    subtree_size[u] = 1;
    depth[u] = 1 + depth[p];
    for(int v: tree[u]) {
        if(v == p) continue;
        dfs1(v, u);
        subtree_size[u] += subtree_size[v];
        if(subtree_size[v] > subtree_size[heavy_child[u]])
            heavy_child[u] = v;
    }
}

void dfsHLD(int u, int chain, int p = 0) {
    head[u] = chain;
    index_of[u] = curr_index++;
    if(heavy_child[u] != 0) 
        dfsHLD(heavy_child[u], chain, u);
    for(int v: tree[u]) {
        if(v == p) continue;
        if(heavy_child[u] != v)
            dfsHLD(v, v, u);
    }
}

int get_lca(int a, int b) {
    // head of different chain cannot be same 
    while(head[a] != head[b]) {
        if(depth[head[a]] < depth[head[b]])
            swap(a, b);
        a = parent[head[a]];
    }
    return depth[a] < depth[b] ? a : b;
}

void solve_problem(int t) {
    // no chain intersects each other
    // each node of tree is unique

    int n;
    cin >> n;

    for(int i = 0; i <= n; i++) {
        tree[i].clear();
        subtree_size[i] = 0;
        depth[i] = 0;
        parent[i] = 0;
        heavy_child[i] = 0;
        head[i] = 0;
    }

    // for(int i = 1; i <= n-1; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     tree[u].push_back(v);
    //     tree[v].push_back(u);
    // }

    for(int u = 1; u <= n; u++) {
        int m;
        cin >> m;
        for(int j = 1; j <= m; j++) {
            int v;
            cin >> v;
            tree[u].push_back(v);
        }
    }

    // heavy light decompose
    dfs1(1);
    dfsHLD(1, 1);

    int q;
    cin >> q;

    cout << "Case " << t << ":" << endl;
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << get_lca(a, b) << endl;
    }
}

/*****main function*****/
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
    // while(test--) solve_problem();

    int t = 1;
    while(t <= test) solve_problem(t++);
 
    return 0;
} 

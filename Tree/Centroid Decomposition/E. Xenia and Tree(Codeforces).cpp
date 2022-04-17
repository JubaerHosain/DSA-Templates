//https://codeforces.com/problemset/problem/342/E

//==============================================
#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****Binary Lifting and LCA*****/
const int N = 2e5+5;
const int inf = 1e9;
set<int> tree[N];
vector<int> depth(N, 0);
int up[N][20];

void binary_lifting(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p;
    for(int i = 1; i < 20; i++) {
        if(up[u][i-1] != -1) 
            up[u][i] = up[up[u][i-1]][i-1];
        else
            up[u][i] = -1;
    }
    for(int v: tree[u]) {
        if(v == p) continue;
        binary_lifting(v, u, d+1);
    }
}

int get_lca(int a, int b) {
    if(depth[a] > depth[b])
        swap(a, b);
    int k = depth[b] - depth[a];
    for(int i = 19; i >= 0; i--) {
        if(k >= (1<<i))  {
            b = up[b][i];
            k -= (1<<i);
        }
    }
    if(a == b)
        return a;
    for(int i = 19; i >= 0; i--) {
        if(up[a][i] != -1 && (up[a][i] != up[b][i]))
            a = up[a][i], b = up[b][i];
    }
    return up[a][0];
}

int get_dist(int a, int b) {
    int lca = get_lca(a, b);
    int dist = depth[a] + depth[b] - 2*depth[lca];
    return dist;
}
 
/*****Centroid Decomposition*****/
vector<int> board(N, inf);
vector<int> parent(N, 0);
vector<int> subtree_size(N);

int find_subtree(int u, int p) {
    subtree_size[u] = 1;
    for(int v: tree[u]) {
        if(v == p) continue;
        subtree_size[u] += find_subtree(v, u);
    }
    return subtree_size[u];
}

int find_centroid(int u, int p, int n) {
    for(int v: tree[u]) {
        if(v != p && subtree_size[v] > n/2)
            return find_centroid(v, u, n);
    }
    return u;
}

void decompose_tree(int u, int p) {
    int size = find_subtree(u, 0);
    int centroid = find_centroid(u, p, size);
    parent[centroid] = p;
    for(int v: tree[centroid]) {
        tree[v].erase(centroid);
        decompose_tree(v, centroid);
    } 
}

void update(int u) {
    int curr = u;
    board[u] = 0;
    while(curr != 0) {
        board[curr] = min(board[curr], get_dist(u, curr));
        curr = parent[curr];
    }
}

int query(int u) {
    int curr = u;
    int ans = inf;
    while(curr != 0) {
        ans = min(ans, board[curr] + get_dist(u, curr));
        curr = parent[curr];
    }
    return ans;
}

/*****User defined function*****/
void solve_problem() {
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].insert(v);
        tree[v].insert(u);
    }

    binary_lifting(1, -1, 0);

    decompose_tree(1, 0);

    // initially 1 is red 
    update(1);

    // for(int i = 1; i <= n; i++)
    //     cout << board[i] << " ";
    // cout << endl;
    
    // for(int i = 1; i <= n; i++)
    //     cout << i << " " << parent[i] << endl;
    // cout << endl;


    while(q--) {
        int t, v;
        cin >> t >> v;
        if(t == 1) 
            update(v);
        else    
            cout << query(v) << endl;
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
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 

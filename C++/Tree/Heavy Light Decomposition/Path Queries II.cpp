#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****Heavy Light Decomposition*****/
const int N = 2e5+5;
vector<int> tree[N];
vector<int> values(N, 0);
vector<int> flatten_values(N, 0);
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
    // next two lines are same as euler tour
    flatten_values[curr_index] = values[u];
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
 
/*****Segment Tree*****/
vector<int> seg_tree(4*N);
 
int buildST(int i, int l, int r) {
    if(l == r) 
        return seg_tree[i] = flatten_values[l];
    
    int mid = (l + r) / 2;
    return seg_tree[i] = max(buildST(2*i+1, l, mid), buildST(2*i+2, mid+1, r));
}
 
int get_max(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)          // total overlap
        return seg_tree[i];
    else if(sr < l || r < sl)       // no overlap;
        return INT_MIN;
 
    int mid = (sl + sr) / 2;
    return max(get_max(2*i+1, sl, mid, l, r), get_max(2*i+2, mid+1, sr, l, r));
}
 
void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {                           //update in the leaf node of the tree
        seg_tree[i] = val;
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else 
        update(2*i+2, mid+1, sr, pos, val);
    
    seg_tree[i] = max(seg_tree[2*i+1], seg_tree[2*i+2]);  //update intermediate nodes after returning the value of the leaf node
}
 
int get_max(int l, int r, int n) {
    return get_max(0, 0, n-1, l, r);
}
 
void update(int pos, int val, int n) {
    flatten_values[pos] = val;
    update(0, 0, n-1, pos, val);
}
 
 
/*****User defined function*****/
int find_ans(int a, int b, int n) {
    int lca = get_lca(a, b);
    int ans = 0;
 
    // a to lca 
    while(head[a] != head[lca]) {
        ans = max(ans, get_max(index_of[head[a]], index_of[a], n));
        a = parent[head[a]];
    }
    ans = max(ans, get_max(index_of[lca], index_of[a], n));
 
    // b to lca 
    while(head[b] != head[lca]) {
        ans = max(ans, get_max(index_of[head[b]], index_of[b], n));
        b = parent[head[b]];
    }
    ans = max(ans, get_max(index_of[lca], index_of[b], n));
 
    return ans;
}
 
void solve_problem() {
    // no chain intersects each other
    // each node of tree is unique
 
    int n, q;
    cin >> n >> q;
 
    for(int i = 0; i <= n; i++) {
        tree[i].clear();
        subtree_size[i] = 0;
        depth[i] = 0;
        parent[i] = 0;
        heavy_child[i] = 0;
        head[i] = 0;
        values[i] = 0;
        curr_index = 0;
    }
 
    for(int i = 1; i <= n; i++)
        cin >> values[i];
 
    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
 
    // heavy light decompose
    dfs1(1);
    dfsHLD(1, 1);
 
    buildST(0, 0, n-1);
 
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int s, x;
            cin >> s >> x;
            int pos = index_of[s];
            update(pos, x, n);
        }
        else {
            // get sum from s to root 
            int a, b;
            cin >> a >> b;
            cout << find_ans(a, b, n) << " ";
        }
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

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
const int N = 1e5+5;
const int inf = 1e9+5;

/*************Euler tour*************/
vector<int> g[N];
vector<pii> tree;               //segment tree array
int first_index[N];             //first index of euler path;
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

pii buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = {depth[l], l};
    
    int mid = (l + r) / 2;
    return tree[i] = min(buildST(2*i+1, l, mid), buildST(2*i+2, mid+1, r));
}

pii get_min(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)          // total overlap
        return tree[i];
    else if(sr < l || r < sl)       // no overlap;
        return {INT_MAX, -1};

    int mid = (sl + sr) / 2;
    return min(get_min(2*i+1, sl, mid, l, r), get_min(2*i+2, mid+1, sr, l, r));
}

pii get_min(int l, int r, int n) {
    return get_min(0, 0, n-1, l, r);
}

void build_euler_tour() {
    dfs_euler(1, -1, 0);
    tree.resize(4*depth.size());
    buildST(0, 0, depth.size()-1);
}


/*************User defined function*************/
void solve() {
    int n;
    cin >> n;

    rep(i, 0, n) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    build_euler_tour();
    
    pii a = get_min(4, 5, depth.size());
    out(a.first, a.second);
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
    //cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}    

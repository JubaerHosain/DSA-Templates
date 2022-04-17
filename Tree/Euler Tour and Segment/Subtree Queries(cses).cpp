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

/*************Range Sum Query*************/
const int N = 2e5+5;
int a[N];
ll tree[4*N];

ll buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = a[l];
    
    int mid = (l + r) / 2;
    return tree[i] = buildST(2*i+1, l, mid) + buildST(2*i+2, mid+1, r);
}

ll get_sum(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)          // total overlap
        return tree[i];
    else if(sr < l || r < sl)       // no overlap;
        return 0;

    int mid = (sl + sr) / 2;
    return get_sum(2*i+1, sl, mid, l, r) + get_sum(2*i+2, mid+1, sr, l, r);
}

void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {                                      //update in the leaf node of the tree
        tree[i] = val;
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else 
        update(2*i+2, mid+1, sr, pos, val);
    
    tree[i] = tree[2*i+1] + tree[2*i+2];               //update intermediate nodes after returning the value of the leaf node
}

ll get_sum(int l, int r, int n) {
    return get_sum(0, 0, n-1, l, r);
}

void update(int pos, int val, int n) {
    a[pos] = val;
    update(0, 0, n-1, pos, val);
}
 
/*************User defined function*************/
int timer = 0;
vector<int> g[N];
int values[N], start[N], sub[N];

void dfs(int u, int p) {
    sub[u] = 1;
    start[u] = timer++;
    a[start[u]] = values[u];
    for(int v: g[u]) {
        if(v == p) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    rep(i, 1, n+1) cin >> values[i];
 
    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    buildST(0, 0, n-1);

    while(q--) {
        int t, s, x;
        cin >> t;
        if(t == 1) {
            cin >> s >> x;
            update(start[s], x, n);
        } else {
            cin >> s;
            print(get_sum(start[s], start[s]+sub[s]-1, n));
        }
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
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
}

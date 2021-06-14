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
vector<int> g[N];
int dep[N], ans[N];

void height(int u, int p) {
    int mx = 0;
    for(int v: g[u]) {
        if(v == p) continue;
        height(v, u);
        mx = max(mx, 1 + dep[v]);
    }
    dep[u] = mx;
}

void dfs(int u, int p, int prnt_max) {
    vector<int> suffix_max, prefix_max;
    for(int v: g[u]) {
        if(v == p) continue;
        prefix_max.push_back(dep[v]);
        suffix_max.push_back(dep[v]);
    }

    int n = prefix_max.size();
    rep(i, 1, n) prefix_max[i] = max(prefix_max[i], prefix_max[i-1]);
    rrep(i, n-2, 0) suffix_max[i] = max(suffix_max[i], suffix_max[i+1]);

    int i = 0;
    for(int v: g[u]) {
        if(v == p) continue;
        int left_max = (i == 0) ? -1 : prefix_max[i-1];
        int right_max = (i == n-1) ? -1 : suffix_max[i+1];
        int parent_max = 1 + max(prnt_max, max(left_max, right_max));
        dfs(v, u, parent_max);
        i++;
    }

    ans[u] = 1 + max(prnt_max, n == 0 ? -1 : prefix_max.back());
}

void solve() {
    int n;
    cin >> n;

    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    height(1, 0);
    dfs(1, 0, -1);
    
    rep(i, 1, n+1) cout << ans[i] << " ";
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

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
ll ans[N];
vector<int> g[N];
ll cnt[N], dist[N], dist_sum[N];

void dfs(int u, int p, int d) {
    cnt[u] = 1;
    dist[u] = d;
    dist_sum[u] = d;
    for(int v: g[u]) {
        if(v == p) continue;
        dfs(v, u, d+1);
        cnt[u] += cnt[v];
        dist_sum[u] += dist_sum[v];
    }
}

void dfs1(int u, int p, int n) {
    //ans[u] =  ans[p] - (dist_sum[u] - cnt[u]*(dist[u]-1)) 
    //+ n - cnt[u] + dist_sum[u] - cnt[u]*dist[u];
    ans[u] = ans[p] + n - 2 * cnt[u];            //simplified equation
    for(int v: g[u]) {
        if(v == p) continue;
        dfs1(v, u, n);
    }
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

    dfs(1, 0, 0);
    ans[1] = dist_sum[1];
    for(int v: g[1]) dfs1(v, 1, n);

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

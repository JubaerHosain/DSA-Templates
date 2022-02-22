#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
ll inf = 1e15+5;
int mod = 1e9+7;
const int N = 5e2+5;
ll dist[N][N];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    rep(i, 1, n) rep(j, 1, n) {
        if(i == j) dist[i][j] = 0;
        else dist[i][j] = inf;
    }

    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], (ll)w);
        dist[v][u] = min(dist[v][u], (ll)w);
    }

//    using k as intermediary node 
    rep(k, 1, n) {
        rep(i, 1, n) rep(j, 1, n) 
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    while(q--) {
        int u, v;
        cin >> u >> v;
        if(dist[u][v] == inf) 
            print(-1);
        else    
            print(dist[u][v]);
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
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 

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
typedef vector<vector<ll>> vii;

/*****User defined function*****/
ll inf = 1e17+5;
int mod = 1e9+7;
const int N = 1e5+5;
vector<pii> g[N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    rep(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    vii dist(n+1, vector<ll>(k, inf));
    dist[1][0] = 0;

    priority_queue<pii> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        ll d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(dist[u][k-1] < d)
            continue;

        for(auto it: g[u]) {
            int v = it.first;
            int w = it.second;
            if(d + w < dist[v][k-1]) {
                dist[v][k-1] = d + w;
                pq.push({-dist[v][k-1], v});
                sort(all(dist[v]));
            }
        }
    }

    rep(i, 0, k-1) cout << dist[n][i] << ' ';
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

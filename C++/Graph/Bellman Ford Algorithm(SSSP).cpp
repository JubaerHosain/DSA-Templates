/*
    1. Bellman-ford Algo is a SSSP Algo that works with negative edge where Dijkstra is not.
    2. Can detect and print negative weight cycle.
    3. When negative weight cycle exist then answer may be wrong.
    4. Undirected graph with negative edge always contains such cycle.
    5. N th iteration dectect the cycle.
    6. Trace back n times so that x becomes a node part of cycle. Because, This vertex 
    will either lie in a negative weight cycle, or is reachable from it(but not in the cycle).
*/


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
ll inf = 1e17+5;
int mod = 1e9+7;
const int N = 2500+5;
ll dist[N];
int parent[N];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pii>> edges;

    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    //disr[src] = 0;
    //parent[src] = -1;
    //if sssp then initialize dist with inf
    fill(dist, dist+N, 0);

    //need n-1 opertion but n th operation detect cycle;
    int x = -1;
    rep(i, 1, n) {
        x = -1;
        for(auto it: edges) {
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(dist[u] != inf && dist[u] + w < dist[v]) {
                x = v;
                parent[v] = u;
                dist[v] = dist[u] + w;
            }
        }
        if(x == -1) break;
    }

    if(x == -1) {
        print("NO");
        return;
    }

    //trace back n times so that x becomes a node part of cycle
    rep(i, 1, n) x = parent[x];

    vector<int> cycle;
    for(int v = x; ; v = parent[v]) {
        cycle.push_back(v);
        if(v == x && cycle.size() > 1) 
            break;
    }

    reverse(cycle.rbegin(), cycle.rend());

    print("YES");
    for(int v: cycle) cout << v << " ";
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

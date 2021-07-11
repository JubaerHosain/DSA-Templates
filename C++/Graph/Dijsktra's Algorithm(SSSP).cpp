#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*
    1. Dijkstra Algo and Bellman-Ford Algo can't find shortest path with 
        negative weight cycle.
    2. Dijkstra can't detect, but Bellman-Ford can detect negative weight cycle.
    3. Bellman-Ford does not work with undirected graph with negative edges as 
        it will declared as negative weight cycle.
    4. Dijkstra doesn’t work for Graphs with negative weight "edges", 
        Bellman-Ford works for such graphs.
*/

 
/*****User defined function*****/
int inf = 1e9+5;
int mod = 1e9+7;
const int N = 1e3+5;
vector<pii> g[N];
int parent[N], used[N];
vector<int> dist(N, inf);

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    memset(used, 0, sizeof(used));
    memset(parent, -1, sizeof(parent));

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    parent[1] = -1;

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int u = p.second;

        if(used[u])
            continue;

        used[u] = 1;
        for(auto it: g[u]) {
            int v = it.second, w = it.first;
            if(!used[v] && dist[u] + w < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    rep(i, 1, n) {
        cout << i << "-> " << dist[i] << endl;
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

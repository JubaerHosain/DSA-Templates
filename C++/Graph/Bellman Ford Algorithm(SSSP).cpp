/*
    1. Dijkstra Algo and Bellman-Ford Algo can't find shortest path with 
        negative weight cycle.
    2. Dijkstra can't detect, but Bellman-Ford can detect negative weight cycle.
    3. Bellman-Ford does not work with undirected graph with negative edges as 
        it will declared as negative weight cycle.
    4. Dijkstra doesn’t work for Graphs with negative weight edges, 
        Bellman-Ford works for such graphs.
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
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int inf = 1e9+5;
int mod = 1e9+7;
const int N = 1e3+5;
int parent[N];
vector<int> dist(N, inf);

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pii>> edges;

    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    bool updated;
    memset(parent, -1, sizeof(parent));
    dist[1] = 0;
    parent[1] = -1;
    rep(i, 1, n-1) {
        updated = false;
        for(auto it: edges) {
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(dist[u] != inf && dist[u] + w < dist[v]) {
                parent[v] = u;
                updated = true;
                dist[v] = dist[u] + w;
            }
        }
        if(updated) break;
    }

    //negative weight cycle contains or not
    updated = false;
    for(auto it: edges) {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(dist[u] != inf && dist[u] + w < dist[v]) {
            parent[v] = u;
            updated = true;
            dist[v] = dist[u] + w;
            break;
        }
    }

    if(updated) {
        print("Negative weight cycle found");

        int u = node;
        vector<int> cycle;
        while(1) {
            cycle.push_back(u);
            if(u == node && cycle.size() > 1)
                break;
            u = parent[u];
        }

        reverse(cycle.rbegin(), cycle.rend());
        for(int v: cycle) cout << v << " ";
        
        return;
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

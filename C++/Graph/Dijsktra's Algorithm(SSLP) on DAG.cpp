/*
    Dijkstra assumes monotonicity. Monotonicity means a function is either
    non-decreasing or non-increasing. ie: All positive edge or all negative edge.
    Graph must not contain negative weight cycle.
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
typedef vector<vector<ll>> vii;

// FINDING LONGEST PATH

/*****User defined function*****/
int inf = 1e9+5;
int mod = 1e9+7;
const int N = 1e5+5;
vector<pii> g[N];
int dist[N], parent[N];

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, -1});
    }

    priority_queue<pii> pq;
    dist[1] = 0;
    parent[1] = -1;
    pq.push({0, 1});
    while(!pq.empty()) {
        int d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        //using visited array 
        //will not work here
        if(dist[u] < d)
            continue;

        for(auto it: g[u]) {
            int v = it.first;
            int c = it.second;
            if(dist[u] + c < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + c;
                pq.push({-dist[v], v});
            }
        }
    }

    if(dist[n] == 0) {
        print("IMPOSSIBLE");
        return;
    }

    vector<int> path;
    for(int v = n; v != -1; v = parent[v])
        path.push_back(v);

    print(path.size());
    rrep(i, path.size()-1, 0)
        cout << path[i] << " ";
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

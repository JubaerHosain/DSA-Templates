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
int inf = 1e9+5;
int mod = 1e9+7;
const int N = 1e5+5;
vector<int> g[N];
int in_degree[N];
int dist[N], parent[N];

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        in_degree[v]++;
        g[u].push_back(v);
    }

    queue<int> q; 
    rep(i, 1, n) {
        if(in_degree[i] == 0)
            q.push(i);
    }

    vector<int> order;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for(int v: g[u]) {
            in_degree[v]--;
            if(in_degree[v] == 0)
                q.push(v);
        }
    }

    fill(dist, dist+N, -inf);

    dist[1] = 0;
    parent[1] = -1;
    for(int u: order) {
        if(dist[u] == -inf)
            continue;

        //weight of each edge is 1
        for(int v: g[u]) {
            if(dist[v] < dist[u] + 1) {
                parent[v] = u;
                dist[v] = dist[u] + 1;
            } 
        }
    }

    if(dist[n] == -inf) {
        print("IMPOSSIBLE");
        return;
    }

    vector<int> path;
    for(int v = n; v != -1; v = parent[v]) 
        path.push_back(v);

    reverse(path.rbegin(), path.rend());

    print(path.size());
    for(int v: path) cout << v << " ";
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

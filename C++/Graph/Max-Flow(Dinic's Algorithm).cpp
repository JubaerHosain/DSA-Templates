/*
    residual capacitty actually the current capacity of an edge.
    initially same as capacity of edge bcz there is no flow.
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
ll inf = 1e18+5;
int mod = 1e9+7;
const int N = 5e2+5;
int level[N];
ll graph[N][N];

bool bfs(int src, int dest, int n) {
    rep(i, 1, n) level[i] = -1;

    queue<int> q;
    q.push(src);
    level[src] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        rep(v, 1, n) {
            if(level[v] == -1 && graph[u][v] > 0) {
                q.push(v);
                level[v] = 1 + level[u];
            }
        }
    }

    return level[dest] != -1;
}

ll send_flow(int u, int dest, int n, ll flow) {
    if(u == dest)
        return flow;

    rep(v, 1, n) {
        if(level[v] == 1+level[u] && graph[u][v] > 0) {
            ll curr_flow = min(flow, graph[u][v]);
            ll min_cap = send_flow(v, dest, n, curr_flow);

            if(min_cap > 0) {
                graph[u][v] -= min_cap;
                graph[v][u] += min_cap;
                return min_cap;
            }
        }
    }

    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] += c;
    }

    int src = 1;
    int dest = n;
    
    ll max_flow = 0;
    while(bfs(src, dest, n)) {
        while(1) {
            ll curr_flow = send_flow(src, dest, n, inf);
            if(curr_flow <= 0 || curr_flow == inf)
                break;
            max_flow += curr_flow;
        }
    }

    print(max_flow);
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

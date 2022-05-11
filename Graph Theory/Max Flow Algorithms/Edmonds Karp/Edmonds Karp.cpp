/*
    Residual capacity = capacity - flow
    Residual capacitty actually the current capacity of an edge. Initially same as capacity of edge bcz there is no flow.

    Edmonds-Karp algorithm is just an implementation of the Ford-Fulkerson method that uses BFS for finding augmenting paths.

    reverse edge(initialy 0)
    augmenting path
    reverse edges exixts to "undo" bad augmenting path which do not lead to a maximum flow

    The above implementation of Ford Fulkerson Algorithm is called Edmonds-Karp Algorithm. The idea of Edmonds-Karp is to use BFS in Ford 
    Fulkerson implementation as BFS always picks a path with minimum number of edges. When BFS is used, the worst case time complexity can 
    be reduced to O(VE^2). The above implementation uses adjacency matrix representation though where BFS takes O(V2) time, the time complexity
    of the above implementation is O(EV3) (Refer CLRS book for proof of time complexity)
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
bool used[N];
int parent[N], graph[N][N], g[N][N];

bool bfs(int src, int dest, int n) {
    fill(used, used+n+1, false);

    queue<int> q;
    q.push(src);
    used[src] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        rep(v, 1, n) {
            if(!used[v] && graph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                used[v] = true;

                if(v == dest)
                    return true;
            }
        }
    }

    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u][v] = c;
        graph[u][v] = c;
    }

    int src, dest;
    cin >> src >> dest;
    
    int max_flow = 0;
    while(bfs(src, dest, n)) {
        int curr_flow = inf;

        for(int v = dest; v != src; v = parent[v]) {
            int u = parent[v];
            curr_flow = min(curr_flow, graph[u][v]);
        }

        for(int v = dest; v != src; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= curr_flow;   //residual capacity
            graph[v][u] += curr_flow;   //reverse edge
        }

        max_flow += curr_flow;
    }

    rep(u, 1, n) rep(v, 1, n)
        if(g[u][v] > 0) 
        cout << u << " " << v << " " << g[u][v] - graph[u][v] << endl;

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
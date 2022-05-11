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
ll inf = 1e18+5;
int mod = 1e9+7;
const int N = 5e2+5;
bool used[N];
int parent[N];
ll graph[N][N];

bool bfs(int src, int dest, int n) {
    rep(i, 1, n) used[i] = 0;

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
        graph[u][v] += c;
    }

    int src = 1;
    int dest = n;
    
    ll max_flow = 0;
    while(bfs(src, dest, n)) {
        ll curr_flow = inf;

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

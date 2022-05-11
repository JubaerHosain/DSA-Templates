/*
    In computer science and optimization theory, the max-flow min-cut theorem states that in a flow network, 
    the maximum amount of flow(max-flow) passing from the source to the sink is equal to the total weight of the edges in a minimum cut, 
    i.e.minimum cut: the smallest total weight of the edges which if removed would disconnect the source from the sink.

    Following are steps to print all edges of the minimum cut.
    1) Run Ford-Fulkerson/Edmond-Karp algorithm and consider the final residual graph.
    2) Find the set of vertices that are reachable from the source in the residual graph.
    3) All edges which are from a reachable vertex to non-reachable vertex are minimum cut edges. Print all such edges.

    HERE I USED DINIC'S ALGO IN UNDIRECTED GRAPH
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
int level[N], used[N];
ll graph[N][N], orginal[N][N]; //residual and orginal graph

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

void reachable(int src, int n) {
    memset(used, 0, sizeof used);

    queue<int> q;
    q.push(src);
    used[src] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        rep(v, 1, n) {
            if(!used[v] && graph[u][v] > 0) {
                q.push(v);
                used[v] = 1;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        graph[u][v]++, graph[v][u]++;
        orginal[u][v]++, orginal[v][u]++;
    }

    int src = 1;
    int dest = n;
    
    while(bfs(src, dest, n)) {
        while(1) {
            ll curr_flow = send_flow(src, dest, n, inf);
            if(curr_flow <= 0 || curr_flow == inf)
                break;
        }
    }

    //mark reachable nodes
    reachable(src, n);

    vector<pii> cuts;
    rep(u, 1, n) rep(v, 1, n) {
        if(used[u] && !used[v] && orginal[u][v] > 0) 
            cuts.push_back({u, v});
    }

    print(cuts.size());
    for(pii it: cuts)
        cout << it.first << " " << it.second << endl;
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


// Dinic's Algo


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
const int inf = 1e9;
const int N = 1e2+5;
int level[N], matrix[N][N];
vector<int> g[N];

bool bfs(int src, int dest, int n) {
    for(int i = 1; i <= n; i++) level[i] = -1;

    queue<int> q;
    q.push(src);
    level[src] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: g[u]) {
            if(level[v] == -1 && matrix[u][v] > 0) {
                q.push(v);
                level[v] = 1 + level[u];
            }
        }
    }

    return level[dest] != -1;
}

int send_flow(int u, int dest, int n, int flow, int p = 0) {
    if(u == dest)
        return flow;

    for(int v: g[u]) {
        if(v == p) continue;
        if(level[v] == 1+level[u] && matrix[u][v] > 0) {
            ll curr_flow = min(flow, matrix[u][v]);
            ll min_cap = send_flow(v, dest, n, curr_flow, u);

            if(min_cap > 0) {
                matrix[u][v] -= min_cap;
                matrix[v][u] += min_cap;
                return min_cap;
            }
        }
    }

    return 0;
}

void solve(int t) {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            matrix[i][j] = 0;
        g[i].clear();
    }
    
    int src, dest, m;
    cin >> src >> dest >> m;

    for(int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        matrix[u][v] += c;
        matrix[v][u] += c;
    }

    // make adj list from adj matrix
    // why adj list? to imporve bfs
    // why from adj matrix ? 
    // if there have multiple edge between two node then consider them one adding all weights
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(matrix[i][j] > 0)
                g[i].push_back(j);
        }
    }
    
    int max_flow = 0;
    while(bfs(src, dest, n)) {
        while(1) {
            int curr_flow = send_flow(src, dest, n, inf);
            if(curr_flow <= 0 || curr_flow == inf)
                break;
            max_flow += curr_flow;
        }
    }

    cout << "Case " << t << ": " << max_flow << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    int test = 1;
    cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i);
 
    return 0;
} 

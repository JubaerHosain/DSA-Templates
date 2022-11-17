// edmond karp
// split node into two part and add node capacity as edge between these two node.

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
const ll inf = 1e15;
const int N = 2e2+5;
bool used[N];
int parent[N];
ll graph[N][N];

bool bfs(int src, int dest, int n) {
    for(int i = 0; i < N; i++)
		used[i] = false;

    queue<int> q;
    q.push(src);
    used[src] = true;
    parent[src] = -1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v = 1; v <= n; v++) {
            if(!used[v] && graph[u][v]) {
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

void solve(int t) {
	// reset graph
	for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            graph[i][j] = 0;
    }


    int n;
    cin >> n;

	// node capacity as edge
    for(int u = 1; u <= n; u++) {
		int capacity;
		cin >> capacity;
		int in = u, out = n+u;

		// make this edge undirected
		graph[in][out] = capacity;

        // uni-direction also works for that problem
		// graph[out][in] = capacity;
	}

    int m; 
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

		int out = n + u;
        graph[out][v] += c;
    }

    int src = 0, dest = 2*n+1;

    int b, d;
    cin >> b >> d;

    for(int i = 1; i <= b; i++) {
        int u; 
        cin >> u;
        graph[src][u] = inf;
    }

    for(int i = 1; i <= d; i++) {
        int u; 
        cin >> u;
        int out = n+u;
        graph[out][dest] = inf;
    }
    
    ll max_flow = 0;
    while(bfs(src, dest, 2*n+1)) {
        ll curr_flow = inf;

        for(int v = dest; v != src; v = parent[v]) {
            int u = parent[v];
            curr_flow = min(curr_flow, graph[u][v]);
        }

        for(int v = dest; v != src; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= curr_flow;   // residual capacity
            graph[v][u] += curr_flow;   // reverse edge
        }
		if(curr_flow < inf)
        	max_flow += curr_flow;
    }

    cout << "Case " << t << ": " << max_flow << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    int test; cin >> test;
    for(int i = 1; i <= test; i++)
        solve(i);
 
    return 0;
} 


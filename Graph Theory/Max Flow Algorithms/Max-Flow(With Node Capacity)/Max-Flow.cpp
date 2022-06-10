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
int city_capacity[N];
int parent[N], graph[N][N], g[N][N];

bool bfs(int src, int dest, int n) {
    fill(used, used+n+1, false);

    queue<int> q;
    q.push(src);
    used[src] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v = 1; v <= n; v++) {
            if(!used[v] && graph[u][v] > 0 && city_capacity[v] > 0 && city_capacity[u] > 0) {
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
    int nodes, edges;
    cin >> nodes >> edges;

    // {ecoding, capacity}
    map<string, pair<int, int>> cities;
    for(int i = 1; i <= nodes; i++) {
        string city;
        int capacity;
        cin >> city >> capacity;
        cities[city] = {i, capacity};
        city_capacity[i] = capacity;
    }


    map<string, pair<string, int>> mp;
    for(int i = 0; i < edges; i++) {
        string src, dest;
        int capacity;
        cin >> src >> dest >> capacity;
        int u = cities[src].first;
        int v = cities[dest].first;
        graph[u][v] = capacity;
    }


    cout << "Initial graph: " << endl;
    for(int i = 1; i <= nodes; i++) {
        for(int j = 1; j <= nodes; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    cout << "Initial city capacity:";
    for(int i = 1; i <= nodes; i++)
        cout << city_capacity[i] << " ";
    cout << endl;
    

    string src_city, dest_city;
    cin >> src_city >> dest_city;

    int src = cities[src_city].first;
    int dest = cities[dest_city].first;
    
    int max_flow = 0;
    while(bfs(src, dest, N)) {
        int curr_flow = inf;

        for(int v = dest; v != src; v = parent[v]) {
            int u = parent[v];
            curr_flow = min(curr_flow, graph[u][v]);
            curr_flow = min({curr_flow, city_capacity[u], city_capacity[v]});
        }

        for(int v = dest; v != src; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= curr_flow;   //residual capacity
            graph[v][u] += curr_flow;   //reverse edge
            city_capacity[v] -= curr_flow; // reduce city capacity;
        }
        city_capacity[src] -= curr_flow;

        // print residual graph
        cout << endl;
        for(int i = 1; i <= nodes; i++) {
            for(int j = 1; j <= nodes; j++)
                cout << graph[i][j] << " ";
            cout << endl;
        }
        cout << "City capacity: ";
        for(int i = 1; i <= nodes; i++)
            cout << city_capacity[i] << " ";
        cout << endl;

        max_flow += curr_flow;
    }

    cout << "Maximum flow is: " << max_flow << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
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



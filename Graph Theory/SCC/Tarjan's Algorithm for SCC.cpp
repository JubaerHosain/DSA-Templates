//Low-link value of a node copletely depend on dfs order
//The nodes same low-link value may or may not belong same scc
//Tarjan's Algo defines a criteria while update low-link value
//During a dfs, Tarjan's Algo keep track of active nodes
//A node u can use a node v to minimize it's low-link value if and only if node v is in active node list
//If in_time is equal to it's low-link value then it is the root of a scc and we found a scc.

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
int inf = 1e9;
int mod = 1e9+7;
const int N = 1e3+5;
vector<int> g[N];
int in[N], low[N];
stack<int> stk;
bool used[N], on_stack[N];
map<int, vector<int>> scc;
int scc_cnt = 0, timer = 0;

void dfs(int u) {
    stk.push(u);
    in[u] = low[u] = ++timer;
    used[u] = on_stack[u] = true;

    for(int v: g[u]) {
        if(used[v] && on_stack[v]) {
            low[u] = min(low[u], in[v]);
        } else if(!used[v]) {
            dfs(v);
            if(on_stack[v]) 
                low[u] = min(low[u], low[v]);
        }
    }

    if(in[u] == low[u]) {
        ++scc_cnt;
        
        while(!stk.empty()) {
            int v = stk.top();
            stk.pop();
            on_stack[v] = false;
            scc[scc_cnt].push_back(v);
            if(v == u) break;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    rep(i, 1, n) {
        if(!used[i]) 
            dfs(i);
    }

    for(auto it: scc) {
        auto v = it.second;
        cout << it.first << ": ";
        for(int i: v) cout << i << " ";
        cout << endl;
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

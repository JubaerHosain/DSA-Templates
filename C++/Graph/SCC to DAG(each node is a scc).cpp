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
const int N = 1e5+5;
vector<int> g[N], dag[N];
int in[N], low[N], scc[N], indegree[N];
stack<int> stk;
bool used[N], on_stack[N];
int scc_cnt = 0, timer = 0;
ll values[N], dag_values[N], max_ans[N];

//each scc is a node in DAG
//scc using tarjan's algorithm
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
            scc[v] = scc_cnt;
            if(v == u) break;
        }
    }
}

void make_dag(int u) {
    used[u] = true;

    for(int v: g[u]) {
        if(!used[u])
            make_dag(v);

        if(scc[u] != scc[v]) {
            dag[scc[u]].push_back(scc[v]);
            indegree[scc[v]]++;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, n) cin >> values[i];

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    //find SCC
    memset(used, 0, sizeof used);
    rep(i, 1, n) {
        if(!used[i]) 
            dfs(i);
    }

    rep(i, 1, n) {
        dag_values[scc[i]] += values[i];
    }

    //make DAG
    memset(used, 0, sizeof used);
    rep(i, 1, n) {
        if(!used[i])
            make_dag(i);
    }

    //find topological ordering
    queue<int> q; 
    rep(i, 1, scc_cnt) {
        if(indegree[i] == 0) {
            q.push(i);
            max_ans[i] = dag_values[i];
        }
    }

    vector<int> order;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for(int v: dag[u]) {
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }

    //Longest path on DAG using topologicalsorting
    for(int u: order) {
        for(int v: dag[u]) {
            if(max_ans[u] + dag_values[v] > max_ans[v]) 
                max_ans[v] = max_ans[u] + dag_values[v];
        }
    }

    ll ans = 0;
    rep(i, 1, scc_cnt)
        ans = max(ans, max_ans[i]);

    print(ans);
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

*/
  1) Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, 
    push the vertex to stack. In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
  2) Reverse directions of all arcs to obtain the transpose graph.
  3) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. 
    Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. 
    In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).
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
const int N = 1e3+5;
int inf = 1e9, mod = 1e9+7;
bool used[N];
stack<int> stk;
vector<int> g[N], gT[N];

void dfs1(int u) {
    used[u] = true;

    for(int v: g[u]) 
        if(!used[v]) dfs1(v);

    stk.push(u);
}

void dfs2(int u) {
    used[u] = true;
    cout << u << " ";

    for(int v: gT[u]) 
        if(!used[v]) dfs2(v);

}

void solve() {
    int n;
    cin >> n;

    rep(i, 1, n) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    memset(used, false, sizeof(used));
    rep(u, 1, n) {
        if(!used[u])
            dfs1(u);
    }

    //make transpose
    rep(u, 1, n) {
        for(int v: g[u])
            gT[v].push_back(u);
    }

    memset(used, false, sizeof(used));
    while(!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if(!used[u]) dfs2(u);
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

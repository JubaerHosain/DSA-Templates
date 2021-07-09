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
const int N = 1e5+5;
bool used[N];
stack<int> stk;
vector<int> g[N];

void dfs(int u) {
    used[u] = true;

    for(int v: g[u]) {
        if(!used[v])
            dfs(v);
    }

    stk.push(u);
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    // rep(i, 1, n) {
    //     if(!used[i] && cycle()) {
    //         print("No Topological Sort");
    //         return;
    //     }
    // }

    memset(used, false, sizeof(used));
    rep(i, 1, n) {
        if(!used[i])
            dfs(i);
    }

    while(!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
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

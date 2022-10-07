// You are given a tree consisting of n nodes.
// Your task is to determine for each node the sum of the distances from the node to all other nodes.


#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforintera
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*************User defined function*************/
const int N = 2e5+5;
int a[N];
vector<int> g[N];
//sum = subtree size(number of node in this subtree)    
ll sum[N], ans[N], res;

void dfs(int u, int p, int d) {
    res += d;
    sum[u] = 1;

    for(int v: g[u]) {
        if(v == p)
            continue;
        dfs(v, u, d+1);
        sum[u] += sum[v];
    }
}

void dfs1(int u, int p) {
    ans[u] = res;

    for(int v: g[u]) {
        if(v == p)
            continue;

        //re-root to v
        res -= sum[v];
        sum[u] -= sum[v]; 
        res += sum[u];
        sum[v] += sum[u];
        
        dfs1(v, u);

        //restore root to u
        sum[v] -= sum[u];
        res -= sum[u];
        sum[u] += sum[v];
        res += sum[v];
    }
}

void solve() {
    int n;
    cin >> n;

    rep(i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1, 0);
    dfs1(1, -1);

    rep(i, 1, n+1) cout << ans[i] << " ";
} 

/*************main function*************/
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

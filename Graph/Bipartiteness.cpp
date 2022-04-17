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
int color[N];
vector<int> g[N];

bool bipartite(int u, int c = 2) {
    color[u] = c;

    for(int v: g[u]) {
        if(!color[v] && !bipartite(v, c^1))
            return false;  
        else if(color[u] == color[v])
            return false;
    }

    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(color, 0, sizeof(color));
    rep(u, 1, n) {
        if(color[u] == 0 && !bipartite(u)) {
            print("NO");
            return;
        }
    }
    
    print("YES");
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

//The theorem used here is that if 'one' vertex can reach to all other vertex and be reached by all others, 
//then every vertex in this graph can reach all others.

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
const int N = 1e5+5;
bool used[N];
vector<int> g[N], gT[N];

void dfs1(int u) {
    used[u] = true;

    for(int v: g[u]) {
        if(!used[v])
            dfs1(v);
    }
}

void dfs2(int u) {
    used[u] = true;

    for(int v: gT[u]) {
        if(!used[v])
            dfs2(v);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gT[v].push_back(u);
    }

    dfs1(1);
    rep(i, 1, n) {
        if(!used[i]) {
            print("NO");
            cout << 1 << " " << i << endl;
            return;
        }
    }

    memset(used, 0, sizeof used);

    dfs2(1);
    rep(i, 1, n) {
        if(!used[i]) {
            print("NO");
            cout << i << " " << 1 << endl;
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

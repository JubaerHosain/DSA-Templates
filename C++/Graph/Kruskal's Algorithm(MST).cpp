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
vector<int> prnt(N, -1), rnk(N, 1);

int find(int u) {
    if(prnt[u] == -1) return u;
    return prnt[u] = find(prnt[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if(rnk[u] < rnk[v]) swap(u, v);

    rnk[u] += rnk[v];
    prnt[v] = u;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pii>> edges;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    sort(all(edges));

    ll ans = 0;
    for(auto it: edges) {
        int u = find(it.second.first);
        int v = find(it.second.second);

        if(u != v) {
            ans += it.first;
            merge(u, v);
        }
    }

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

// E - Count Descendants: https://atcoder.jp/contests/abc202/tasks/abc202_e?lang=en 

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(a)   a.begin(), a.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 2e5 + 5;
vector<int> g[N];
int start[N], last[N];
vector<int> depth[N];

int timer = 0;
void dfs(int u, int d = 0) {
    start[u] = timer++;
    depth[d].push_back(start[u]);
    for(int v: g[u]) 
        dfs(v, d+1);
    last[u] = timer++;
}

void solve_problem() {
    int n;
    cin >> n;
    rep(i, 2, n) {
        int p; 
        cin >> p;
        g[p].push_back(i);
    }

    dfs(1);

    int q;
    cin >> q;
    while(q--) {
        int u, d;
        cin >> u >> d;
        int l = start[u], r = last[u];
        int ans = lower_bound(all(depth[d]), r) - lower_bound(all(depth[d]), l);
        cout << ans << endl; 
    }
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(5);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();
    
 
    return 0;
} 


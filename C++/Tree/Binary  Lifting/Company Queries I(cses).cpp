#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
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
ll ans[N];
int up[N][20];
vector<int> g[N];
 
// before comming u, all parent of u is processed
void binary_lifting(int u, int p) {
    up[u][0] = p;
    rep(i, 1, 20) {
        if(up[u][i-1] != -1) 
            up[u][i] = up[up[u][i-1]][i-1];
        else
            up[u][i] = -1;
    }
 
    for(int v: g[u]) {
        if(v == p) continue;
        binary_lifting(v, u);
    }
}


// binary lifting iterative apporach
// first find  2^1, then 2^2, then 2^3...for all u
// rep(i, 1, 30) {   this loop shoul be first
//     rep(u, 1, n) {  all parent of u is processed or not don't know. thats why this loop is second
//         up[u][i] = up[up[u][i-1]][i-1];
//     }
// }
 
int query(int u, int k) {
    if(u == -1 || k == 0) 
        return u;
 
    rrep(i, 19, 0) {
        if((1<<i) <= k) 
            return  query(up[u][i], k - (1 << i));
    }
    
    return -1;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    rep(i, 2, n+1) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
 
    binary_lifting(1, -1);
    
    while(q--) {
        int x, k;
        cin >> x >> k;
        print(query(x, k));
    }
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

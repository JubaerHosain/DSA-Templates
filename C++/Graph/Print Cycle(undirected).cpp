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
int node = -1;
vector<int> g[N];
int used[N], parent[N];

bool cycle(int u, int p) {
    used[u] = 1;
    parent[u] = p;

    for(int v: g[u]) {
        if(v == p)
            continue;
        if(!used[v]) {
            if(cycle(v, u))
                return true;;
        } else {
            node = v;
            parent[v] = u;
            return true;
        }
    }

    return false;
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

    rep(i, 1, n) {
        if(!used[i] && cycle(i, -1)) {
            int v = node;
            vector<int> ans;

            while(1) {
                ans.push_back(v);
                if(v == node && ans.size() > 1)
                    break;
                v = parent[v];
            }

            reverse(ans.rbegin(), ans.rend());

            print(ans.size());
            for(int i: ans) cout << i << " ";

            return;
        }
    }

    print("IMPOSSIBLE");
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

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
const int N = 1e3+5;
vector<pii> g[N];
int parent[N], used[N];
vector<int> key(N, inf);

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    memset(parent, -1, sizeof(parent));

    ll min_cost = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    key[1] = 0;
    used[1] = 0;
    parent[1] = -1;

    while(!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int u = p.second;

        if(used[u])
            continue;

        used[u] = 1;
        min_cost += p.first;
        for(auto it: g[u]) {
            int v = it.second, w = it.first;
            if(!used[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }
    
    print(min_cost);
    rep(i, 1, n) {
        if(parent[i] != -1) 
            cout << i << " " << parent[i] << endl;
    }

    //without key array(that stores weight of comming from parent(that is minimal)) 
    //may be parent_array will init by incorrect parent with maximum comming weight.
    //but min_cost will always correct
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

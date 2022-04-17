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

//this code is for Euler cycle but can be modified for Euler path

/*****User defined function*****/
const int N = 1e5+5;
bool used[N];
set<int> g[N];
int degree[N];
vector<int> path;


void component(int u) {
    used[u] = 1;
    for(int v: g[u]) {
        if(!used[v])
            component(v);
    }
}

bool has_euler(int n) {
    rep(i, 1, n) 
        if(degree[i]&1)
            return false;

    memset(used, 0, sizeof used);
    component(1);

    rep(i, 1, n) 
        if(!used[i] && degree[i] != 0)
            return false;

    return true; 
}

void make_path(int u) {
    while(degree[u]) {
        int v = *g[u].begin();
        g[u].erase(v);
        g[v].erase(u);
        degree[u]--, degree[v]--;
        make_path(v);
    }
    path.push_back(u);
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
        degree[u]++, degree[v]++;
    }

    if(!has_euler(n)) {
        print("IMPOSSIBLE");
        return;
    }

    make_path(1);

    while(!path.empty()) {
        cout << path.back() << " ";
        path.pop_back();
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

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
int in_degree[N];
vector<int> g[N];

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        in_degree[v]++;
    }

    vector<int> ans;
    //queue<int> q; 
    //q works, pq for lexicographically smallest
    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, 1, n) {
        if(in_degree[i] == 0)
            pq.push(i);
    }

    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);

        for(int v: g[u]) {
            in_degree[v]--;
            if(in_degree[v] == 0)
                pq.push(v);
        }
    }

    //has cycle
    if(ans.size() != n) {
        print("Sandro fails.");
        return;
    }

    for(int i: ans) cout << i << " ";
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

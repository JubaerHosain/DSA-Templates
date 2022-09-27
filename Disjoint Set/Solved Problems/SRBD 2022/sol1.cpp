#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(v)   v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

const int N = 1e5 + 5;

vector<int> prnt(N, -1), rnk(N, 1);
vector<int> boss(N), level(N);

int find(int u) {
    if(prnt[u] == -1) return u;
    return prnt[u] = find(prnt[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    
    if(u == v) 
        return;

    if(rnk[u] < rnk[v]) swap(u, v);

    rnk[u] += rnk[v];
    prnt[v] = u;
    
    if(level[boss[u]] > level[boss[v]])
        boss[u] = boss[v];
    else if(level[boss[u]] == level[boss[v]])
        boss[u] = max(boss[u], boss[v]);
}

void solve_problem() {
    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        level[x] = i;
        boss[x] = x;
    }
    
    while(q--) {
        int t;
        cin >> t;
        
        if(t == 1) {
            int a, b;
            cin >> a >> b;
            merge(a, b);
        }
        else if(t == 2) {
            int x;
            cin >> x;
            // int l = level[x];
            // if(l == 0) continue;
            
            level[x] -= 1;
            int u = find(x);
            if(level[x] < level[boss[u]]) 
                boss[u] = x;
            else if(level[x] == level[boss[u]])
                boss[u] = max(boss[u], x);
        }
        else {
            int x;
            cin >> x;
            cout << boss[find(x)] << endl;
        }
    }
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // dosen't works in hackerrank
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


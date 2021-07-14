#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> vii;

/*****User defined function*****/
ll inf = 1e17+5;
int mod = 1e9+7;
const int N = 1e5+5;
stack<int> stk;
vector<int> g[N];
bool used[N], on_stk[N];

bool cycle(int u) {
    used[u] = true;
    on_stk[u] = true;
    stk.push(u);

    for(int v: g[u]) {
        if(!used[v]) {
            if(cycle(v))
                return true;
        } else if(on_stk[v]) {
            stk.push(v);
            return true;
        }
    }

    on_stk[stk.top()] = false;
    stk.pop();

    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    bool found = false;
    rep(i, 1, n) {
        if(!used[i] && cycle(i)) {
            found = true;
            break; 
        }
    }

    if(!found) {
        print("IMPOSSIBLE");
        return;
    }

    vector<int> ans;
    int u = stk.top();
    while(!stk.empty()) {
        ans.push_back(stk.top());
        if(stk.top() == u && ans.size() > 1) 
            break;
        stk.pop();
    }

    reverse(ans.rbegin(), ans.rend());

    print(ans.size());
    for(int u: ans) cout << u << " ";
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

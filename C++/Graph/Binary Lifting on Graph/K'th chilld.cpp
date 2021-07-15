
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
ll inf = 1e18+5;
int mod = 1e9+7;
const int N = 2e5+5;
int up[N][31];

int get_query(int x, int k) {
    rrep(i, 30, 0) 
        if(k&(1<<i)) 
            x = up[x][i];

    return x;
}

void solve() {
    int n, q;
    cin >> n >> q;

    //take input reversly for making inverse graph
    //make child to parent
    rep(i, 1, n) cin >> up[i][0];

    //binary lifting
    //this is not working bcz cant find k > 1 th parent for first node
    //but first node may have k > 1 th parent, and next nodes goes to wrong
    // rep(u, 1, n) {
    //     rep(i, 1, 30) {
    //         up[u][i] = up[up[u][i-1]][i-1];
    //     }
    // }

    //binary lifting
    rep(i, 1, 30) {
        rep(u, 1, n) {
            up[u][i] = up[up[u][i-1]][i-1];
        }
    }

    while(q--) {
        int x, k;
        cin >> x >> k;
        print(get_query(x, k));
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

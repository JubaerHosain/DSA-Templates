#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//not for interactive
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 5e2+5;
ll dp[N][N];

void solve() {
    ll n;
    cin >> n;

    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i];

    rep(i, 1, n-1) dp[i][i] = 0;

    rep(l, 2, n-1) rep(i, 1, n-l) {
        int j = i + l - 1;
        dp[i][j] = LONG_MAX;
        rep(k, i, j-1) {
            ll tmp = dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j];
            dp[i][j] = min(dp[i][j], tmp);
        }
    } 
    
    cout << dp[1][n-1] << endl;
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

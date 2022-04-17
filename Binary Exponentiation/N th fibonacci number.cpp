#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//not for interactive
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> vii;


/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e6+5;

vii matrix_mul(vii a, vii b, int n) {
    vii dp(n, vector<ll>(n, 0));

    //multiplication of n*n matrix
    rep(i, 0, n-1) {
        rep(j, 0, n-1) rep(k, 0, n-1) {
            dp[i][j] += (a[i][k]%mod * b[k][j]%mod) % mod;
            dp[i][j] %= mod;
        }
    }

    return dp;
}

vii matrix_pow(vii a, int n, ll x) {
    vii res(n, vector<ll>(n, 0));
    rep(i, 0, n-1) res[i][i] = 1;            //identity matrix

    while(x) {
        if(x&1LL) 
            res = matrix_mul(res, a, n);
        x /= 2;
        a = matrix_mul(a, a, n);
    }

    return res;
}

void solve() {
    ll n;
    cin >> n;

    if(n <= 2) {
        if(n == 0)
            cout << 0 << endl;
        else 
            cout << 1 << endl;
        return;
    } 

    vii a(2, vector<ll>(2, 1));
    a[0][0] = 0;

    a = matrix_pow(a, 2, n-1);
    
    cout << a[1][1]%mod << endl;
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

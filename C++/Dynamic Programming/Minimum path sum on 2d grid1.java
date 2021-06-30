
#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*
    find a path from any cell in first row to
    any cell in the last row which minimize/maximized sum
    moves: down, down-left or down-right
*/

/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e5+5;

void solve() {
    int n;
    cin >> n;

    vii a(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];

    vii dp(n, vector<int>(n, 0));
    rep(i, 0, n) dp[n-1][i] = a[n-1][i];
    rrep(i, n-2, 0) {
        rep(j, 0, n) {
            if(j == 0)
                dp[i][j] = a[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            else if(j == n-1)
                dp[i][j] = a[i][j] + min(dp[i+1][j], dp[i+1][j-1]);
            else   
                dp[i][j] = a[i][j] + min(dp[i+1][j], min(dp[i+1][j-1], dp[i+1][j+1]));
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n) 
            cout << dp[i][j] << " ";
        cout << endl;
    }
 
}


/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    cout << fixed << showpoint;
    cout << setprecision(16);

    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}    

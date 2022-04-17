//jumping 1,2or3 moves to n
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
typedef vector<vector<ll>> vii;

/*************User defined function*************/
int mod = 1e9+7;
const int N = 1e5+5;
ll dp[N];

void solve() {
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    rep(i, 4, n+1) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        dp[i] %= mod;
    }

    print(dp[n]);
} 

/*************main function*************/
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

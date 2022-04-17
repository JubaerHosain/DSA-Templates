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
const int N = 5e3+5;
ll dp[N][N];
 
void solve() {
    string a, b;
    cin >> a >> b;
 
    int n = a.size();
    int m = b.size();
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(i == 0) 
                dp[i][j] = j;
            else if(j == 0) 
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                // {i-1, remove} {j-1, insert}, {replace} converting a to b
        }
    }
 
    print(dp[n][m]);
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

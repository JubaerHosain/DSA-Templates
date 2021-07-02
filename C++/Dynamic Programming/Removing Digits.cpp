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
 
/*****User defined function*****/
int mod = 1e9+7;
int inf = 1e9+5;
 
void solve() {
    int n;
    cin >> n;

    vector<int> dp(n+1, inf);
    dp[n] = 1;
    rrep(i, n, 0) {
        if(dp[i] != inf) {
            int tmp = i;
            while(tmp) {
                int d = tmp%10;
                tmp /= 10;
                dp[i-d] = min(dp[i-d], 1 + dp[i]);
            }
        }
    }

    print(dp[0]-1);
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
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
}   

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
typedef vector<vector<bool>> vii;

/*****User defined function*****/
int mod = 1e9+7;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vii dp(n, vector<bool>(n, false));

    int sz = 1, st = 0;
    rep(i, 0, n)
        dp[i][i] = true;

    rep(i, 0, n-1) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = true;
            st = i, sz = 2;
        }
    }
 
    rep(l, 3, n+1) {
        rep(i, 0, n-l+1) {
            int j = i+l-1;
            if(s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                if(sz < l) 
                    sz = l, st = i;
            }
        }
    }

    print(s.substr(st, sz));
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

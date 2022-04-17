#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define rep(i, s, n) for(int i = s; i < n; i++)
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
int inf = 1e9;

void solve_problem() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int m;
    cin >> m;

    vector<int> inx(26, n);
    vector<int> next(n, n);
    for (int i = n-1; i >= 0; i--) {
        int curr = s[i] - 'a';
        next[i] = inx[(curr+1)%26];
        inx[curr] = i; 
    }

    vector<vector<int>> dp(n, vector<int>(26, n));
    for (int i = 0; i < n; i++)
        dp[i][0] = next[i];

    for (int j = 1; j < 26; j++) {
        for(int i = 0; i < n; i++) {
            if(dp[i][j-1] != n) // boundary case checking IOB
                dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    int ans = inf;
    for (int i = 0; i < n; i++) {
        if(s[i] != 'a') continue;
        int j = i, len = m - 1;  // a is already taken
        for (int k = 25; k >= 0; k--) {
            if(len - (1 << k) >= 0) {
                j = dp[j][k];
                len -= (1 << k);
                if(j == n) break; // nth index gives error
            }
        }
        if(j != n) // inx filled with n
            ans = min(ans, (j-i+1) - m);
    }

    cout << (ans == inf ? -1 : ans) << endl;

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
    cout << setprecision(5);
 
    int test = 1;
    cin >> test;
    while(test--)  solve_problem();
 
    return 0;
} 

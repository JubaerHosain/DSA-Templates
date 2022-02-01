#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 5e2+5;
int dp[N][N];

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        dp[i][i] = 0;

    // started from length two, like longest palindromic substring
    for(int l = 2; l < n; l++) {
        for(int i = 1; i <= n-l; i++) {
            int j = i + l - 1;
            int min_cnt = INT_MAX;
            // divided at right side of index k
            for(int k = i; k < j; k++) {
                int tmp = dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j];
                min_cnt = min(min_cnt, tmp);
            }

            dp[i][j] = min_cnt;
        }
    }

    cout << dp[1][n-1] << endl;
    
//     print parenthesis using recursion, sumon sir slide!!!
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

#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 1e3+5;
ll dp[N][N];
int cost[N][N];

void solve_problem() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) 
            cin >> cost[i][j];
    }

    // first and last column assigned inf 
    for(int i = 1; i <= n; i++) 
        dp[i][0] = dp[i][m+1] = 1e18;

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= m; j++) {
            if(i == n)
                dp[i][j] = cost[i][j];
            else 
                dp[i][j] = cost[i][j] + min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});
        }
    }

    ll ans = 1e18;
    for(int j = 1; j <= m; j++) 
        ans = min(ans, dp[1][j]);

    cout << "Minumum cost is: " << ans << endl;
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
    // cin >> test;
    while(test--) {
        solve_problem();
    }
 
    return 0;
} 
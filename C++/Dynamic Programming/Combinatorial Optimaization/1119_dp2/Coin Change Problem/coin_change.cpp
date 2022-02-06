#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
void solve_problem() {
    int n, sum;
    cin >> n >> sum;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<ll>> dp(n, vector<ll>(sum+1, 0));
    for(int i = 0; i < n; i++)
        dp[i][0] = 1;


    for (int i = 0; i < n; i++) {
        for(int j = 1; j <= sum; j++) {
            int including = 0, excluding = 0;
            // including a[i] 
            // a[i] can multiple times, if use exactly one time then dp[i-1][j-a[i]]
            if(j >= a[i])
                including = dp[i][j-a[i]];
            if(i > 0)
                excluding = dp[i-1][j];
            dp[i][j] = including + excluding;
        }
    }

    cout << "Maximum number of way: " << dp[n-1][sum] << endl;
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
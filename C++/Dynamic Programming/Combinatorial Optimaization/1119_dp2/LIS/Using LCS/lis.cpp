#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 5e5+5;

void solve_problem() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] = b[i];
    }

    // sort a 
    sort(a.begin(), a.end());

    // finding lis using lcs
    // Array should have distinct elements otherwise it might give wrong result
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else    
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    } 

    cout << "Max LIS length: " << dp[n][n] << endl;
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
    //cin >> test;
    while(test--) {
        solve_problem();
    }
 
    return 0;
} 
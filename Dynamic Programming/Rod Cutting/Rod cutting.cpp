#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/

void solve_problem() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++) 
        cin >> prices[i];

    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++)
            dp[j] = max(dp[j], dp[j-i] + prices[i-1]);
    }

    cout << "Maximum price: " << dp[n] << endl;
} 
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(5);
 
    int test = 1;
    // cin >> test;
    while(test--)  solve_problem();
 
    return 0;
} 


// 8
// 1 5 8 9 10 17 17 20
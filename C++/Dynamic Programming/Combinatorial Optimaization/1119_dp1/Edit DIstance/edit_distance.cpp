#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
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
 
    int m = a.size();
    int n = b.size();
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0) 
                dp[i][j] = j;
            else if(j == 0) 
                dp[i][j] = i;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else 
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                // {i-1, remove} {j-1, insert}, {i-1, j-1, replace}
        }
    }
 
    cout << "Minimum Edit Distance: " << dp[m][n] << endl;
}   
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
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
/**
https://www.hackerearth.com/challenges/competitive/november-circuits-22/algorithm/video-game-c971c2a9/
*/

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(v)   v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 1e2 + 5;
int dp[N][N][25];

int dfs(int i, int m, int k, int n, vector<int> &a, vector<int> &v) {
    if(i == n || m <= 0)
        return 0;
    else if(dp[i][m][k] != -1) 
        return dp[i][m][k];

    int keep = 0, skip = 0;
    int tmp_a = a[i], prev_a = 0;
    int tmp_m = m;
    while(tmp_a > 0 && tmp_m > 0) {
        if(tmp_m >= v[i]) {
            keep = max(keep, prev_a + tmp_a + dfs(i+1, tmp_m-v[i], k, n, a, v));
        }
        prev_a += tmp_a;
        tmp_a /= 2;
        tmp_m -= v[i]; 
    }
    
    if(k > 0)
        skip = dfs(i+1, m, k-1, n, a, v);
    
    return dp[i][m][k] = max(keep, skip);
}

void solve_problem() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), v(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // assign all values to -1
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, m, k, n, a, v) << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();

    return 0;
} 





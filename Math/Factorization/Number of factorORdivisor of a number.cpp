// problem link: https://www.hackerearth.com/problem/algorithm/four-prime-factors-e54812c2/

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
const int N = 1e6 + 5;
vector<int> factor(N, 0), dp(N, 0);

void factor_sieve() {
    // nlogn
    // number of factor of n
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) 
            factor[j] += 1;
        dp[i] = factor[i] == 4 ? 1 : 0;
    }

    // prefix sum
    for(int i = 0; i < N; i++)
        dp[i] += dp[i-1];
}

void solve_problem() {
    int l, r;
    cin >> l >> r;
    cout << dp[r] - dp[l-1] << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(15);

    factor_sieve();
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();

    return 0;
} 


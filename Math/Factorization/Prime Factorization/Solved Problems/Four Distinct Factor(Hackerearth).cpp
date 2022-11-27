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
vector<int> factor(N, -1), dp(N, 0);



void factor_sieve() {
    for(int i = 4; i <= N; i += 2) {
        if(factor[i] == -1) 
            factor[i] = 2;
    }

    for(int i = 3; i*i <= N; i += 2) {
        for(int j = 2*i; j <= N; j += i) {
            if(factor[j] == -1)
                factor[j] = i;
        }
    }

    for(int i = 6; i < N; i++) {
        // count of each prime factor
        map<int , int> mp;
        int n = i;
        while(factor[n] != -1) {
            int f = factor[n], cnt = 0;
            while(n%f == 0) {
                n /= f;
                cnt += 1;
            }
            mp[f] = cnt;
        }
        if(n > 1) mp[n] = 1;

        // total number of factor
        int ft_cnt = 1;
        for(auto it: mp) {
            ft_cnt *= (it.second + 1);
        }

        if(ft_cnt == 4) dp[i] = 1;
    }

    for(int i = 6; i < N; i++)
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




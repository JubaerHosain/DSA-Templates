#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 20;
int dp[1<<N][N];

// for dp[i][j], i = subset
// j = the bit till we have gone
// first j bit can be change(only set bits), after j'th bit we cannot change it

void solve_problem() {
    int n = 3;
    vector<int> f(1<<n), h(1<<n);

    // f(i) is given
    // h(i) = sum of all f(x) for all x and x is subset of i
    // considering all set bit

    for(int i = 0; i < (1<<n); i++) {
        cin >> f[i];
        dp[i][0] = f[i];
    }

    // O(n*2^n) complexity
    // swap of this two for loop will work fine
    for(int t = 0; t < (1<<n); t++) {
        for(int i = 1; i <= n; i++) {
            dp[t][i] = dp[t][i-1];
            if(t & (1<<(i-1)))
                dp[t][i] += dp[t^(1<<(i-1))][i-1];
        }
    }

    for(int i = 0; i < (1<<n); i++) 
        h[i] = dp[i][n];

    for(int i = 0; i < (1<<n); i++) 
        cout << h[i] << " ";
    cout << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


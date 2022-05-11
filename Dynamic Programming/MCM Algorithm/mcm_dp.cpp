#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 5e5+5;

void print_parenthesis(vector<vector<int>> &split, int i, int j) {
    if(i == j) {
        cout << "A" << i;
    }
    else {
        cout << "(";
        print_parenthesis(split, i, split[i][j]);
        cout << "*";
        print_parenthesis(split, split[i][j]+1, j);
        cout << ")";
    }
}

void solve_problem() {
    int n;
    cin >> n;

    // there has n-1 matrix
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    vector<vector<int>> split(n, vector<int>(n, 0));

    // r1 * (c1 = r2) * c2
    // started from matrix length two like longest palindromic substring
    for(int l = 2; l < n; l++) {
        for(int i = 1; i <= n-l; i++) {
            int j = i + l - 1;
            dp[i][j] = 1e18;
            // divided at right side of k(index k is included in left part of division)
            for(int k = i; k < j; k++) {
                ll tmp = dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j];
                if(tmp < dp[i][j]) {
                    dp[i][j] = tmp;
                    split[i][j] = k;
                }
            }
        }
    }

    cout << "Min Cost: " << dp[1][n-1] << endl;

    cout << "Parenthesis: ";
    // not from 0 th index
    print_parenthesis(split, 1, n-1);
    cout  << endl;
} 
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(5);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();
    
 
    return 0;
} 
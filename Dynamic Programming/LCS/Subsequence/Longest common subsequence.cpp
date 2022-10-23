#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
const int N = 1e3 + 5;
int dp[N][N];

void solve_problem() {
    string a, b;
    cin >> a >> b;

    int m = a.size();
    int n = b.size();
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else    
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "Length of LCS: " << dp[m][n] << endl;

    int i = m, j = n;
    int sz = dp[m][n];
    string lcs(sz, '*');
    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {
            lcs[sz-1] = a[i-1];
            i--, j--, sz--;
        }
        else if(dp[i][j-1] > dp[i-1][j])
            j--;
        else 
            i--;
    }

    cout << "LCS is: " << lcs << endl;
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


// asdfs
// addefa
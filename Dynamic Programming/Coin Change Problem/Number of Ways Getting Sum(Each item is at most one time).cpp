#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****user defined function*****/

const int N = 1e6 + 5;
ll dp[25][N];

void solve_problem() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= N-1; j++) {
            if(j == 0) {
                dp[i][j] = 1;
            } else {
                if(j < a[i])                // exlcuding a[i] [note: a[i] is one indexing]
                    dp[i][j] = dp[i-1][j];
                else                        // excluding + including {dp[i-1][j-a[i]] for at most 1 time}
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i]];
            }
        }
    }
        
    for(int i = 0; i < m; i++) {
        int qi;
        cin >> qi;

        if(dp[n][qi] == 0) 
            cout << -1 << endl;
        else
            cout << dp[n][qi] << endl;
    }
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
    cout << setprecision(16);

    int test = 1;   
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 
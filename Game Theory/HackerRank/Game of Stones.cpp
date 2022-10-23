
#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(a)   a.begin(), a.end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

 /*
    1. both players plays optimally
    2. first player choose a number such that second player 
    fall into false state.

    a) From the losing state we can move only winning states
    b) From the winning state we can move at least one losing state
*/

/*****User defined function*****/

void solve_problem() {
    const int N = 100;
    
     vector<bool> dp(N+1);
    dp[0] = dp[1] = false;
    dp[2] = dp[3] = dp[4] = dp[5] = true;
    for(int i = 6; i <= N; i++) {
        if(!dp[i-2] || !dp[i-3] || !dp[i-5])
            dp[i] = true;
        else 
            dp[i] = false;
    }
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(dp[n])
            cout << "First" << endl;
        else 
            cout << "Second" << endl;
    }
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << showpoint;
    cout << setprecision(15);
    
    solve_problem();

    return 0;
} 



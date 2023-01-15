#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;


bool possible(vii &grid, int l) {
    int n = grid.size();
    int m = grid[0].size();

    vii dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] >= l) 
                dp[i][j] = 1;
        }
    }

    int ans = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(dp[i][j] == 1) {
                // dp for maximal square
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                ans = max(ans, dp[i][j]);
                if(ans >= l)
                    return true;
            }
        }
    }
        
    return false;
}

void solve_problem() {
    int n, m; 
    cin >> n >> m;

    vii grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    }


    int ans = 1;
    int l = 1, r = min(m, n);
    while(l <= r) {
        int mid = (l+r) / 2;
        if(possible(grid, mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

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


#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****user defined function*****/


// each coin can use exactly one time

const int N = 1e6 + 5;
ll dp[25][N];

void solve_problem() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= N-1; j++) {
            if(j == 0){
                    dp[i][j] = 1;
                }

                else{
                    ll excluding = 0;
                    ll including = 0;
                    
                    if(i > 0){     //excluding coins[i]
                        excluding  = dp[i-1][j];
                    }
                    if(j >= a[i] && i > 0){  //including coins[i]
                        including = dp[i-1][j-a[i]];          //coins[i] can multiple times, if use exactly one time then dp[i-1][j-coins[i]]              
                    }
                    else if(j == a[i] && i == 0) {
                        including = 1;
                    }
                    
                    
                    dp[i][j] = excluding + including;
                }
        }
    }
        
    for(int i = 0; i < m; i++) {
        int qi;
        cin >> qi;

        if(dp[n-1][qi] == 0) 
            cout << -1 << endl;
        else
            cout << dp[n-1][qi] << endl;
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

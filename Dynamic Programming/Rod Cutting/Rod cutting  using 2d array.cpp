// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

typedef long long ll;
typedef vector<vector<ll>> vii;

class Solution{
  public:
    int cutRod(int price[], int n) {
     //every i the is weight of corresponding price 1 to n, as well as index
        //code here
        vii dp(n+1, vector<ll>(n+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(j < i)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j-i]); 
                    // each element can be used multiple times, that's why dp[i][j-i], not dp[i-1][j-i]
            }
        }
        
        return dp[n][n];
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends

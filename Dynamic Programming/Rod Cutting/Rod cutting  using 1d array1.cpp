// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

typedef long long ll;

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<ll> dp(n+1, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i] = max(dp[i], price[j-1] + dp[i-j]);
            }
        }
        
        return dp[n];
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

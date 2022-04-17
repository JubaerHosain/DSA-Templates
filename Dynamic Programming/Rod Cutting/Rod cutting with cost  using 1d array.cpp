// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++
typedef long long ll;

// not tested by more testcase 

class Solution{
  public:
    int cutRod(int price[], int n) {
        // cost per cut 
        int c = 1;
        vector<ll> dp(n+1, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                dp[i] = max(dp[i], price[j-1] + dp[i-j] - c);
            }
            dp[i] = max(dp[i], (ll)price[i-1]);
            // We need to account for cost cc on every iteration 
            //of the loop in lines 5-6 but the last one, when i = j
            //i=j (no cuts).We make the loop run to j - 1
            //j−1 instead of jj, make sure cc is subtracted from 
            //the candidate revenue in line 6, then pick the greater 
            //of current best revenue qq and p[j]p[j] (no cuts) in line 7.
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

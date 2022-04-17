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
      //every i is the weight of corresponding price 1 to n, as well as index
      
      
        //code here
        vector<ll> dp(n+1, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                dp[j] = max(dp[j], max(dp[j-1], price[i-1] + dp[j-i]));
                //dp[j-1] included for, if making j is impossible then copy from previous weight
                // for rod cutting it dosent happens bcz 1 to n all are given length, and all are possible to make.
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


#include<bits/stdc++.h>
using namespace std;


class Solution {
    int mod = 1e9 + 7;
    long long int dp[1005][1005];

    int dfs(int i, int j, string &s) {
        if(i > j)
            return 0;
        else if(i == j)
            return dp[i][j] = 1;
        else if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j]) 
            dp[i][j] = (1 + dfs(i+1, j, s) + dfs(i, j-1, s)) % mod;
        else 
            dp[i][j] = (dfs(i+1, j, s) + dfs(i, j-1, s) - dfs(i+1, j-1, s)) % mod;

        if(dp[i][j] < 0)
            dp[i][j] += mod;

        return dp[i][j];
    }

public:
    long long int countPS(string s) {
        memset(dp, -1, sizeof(dp));

        return dfs(0, s.length()-1, s);
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}




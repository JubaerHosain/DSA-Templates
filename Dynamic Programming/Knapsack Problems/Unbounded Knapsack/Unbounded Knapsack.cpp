// maximizing profit

// using 2d array
rep(i, 1, n+1) {
    rep(j, 1, s+1) {
        if(j < w[i])   // excluding w[i]
            dp[i][j] = dp[i-1][j];
        else           //max(excluding, including) each w[i] can be use at most 1 times.
            dp[i][j] = max(dp[i-1][j], p[i] + dp[i][j-w[i]]);
            // dp[i][j-w[i]] = unbounded knapsack, each elememt can be use multiple time.
            // dp[i-1][j-w[i]] = 0-1 knapsack, each element can be use at most 1 time.
            // w[i] is 1 indexing in this case, if 0 indexing then it should w[i-1]
    }
}

// using 1d array (from gfg)
// Fill dp[] using above recursive formula
// didn't tested by more testcase
for(int i = 0; i <= W; i++){
    for(int j = 0; j < n; j++){
        if(w[j] <= i)                   
            dp[i] = max(dp[i], dp[i - w[j]] + profit[j]);
    }
}

// rod cutting version 
// every i is the weight of corresponding price 1 to n, as well as index
// 2nd loop is for updating all of position that can be updated with weight[i]
// Accepted in pepcoding website
void unboundedKnapsack(int n, vector<int> val, vector<int> weight, int cap) {
    vector<int> dp(cap+1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = weight[i]; j <= cap; j++) 
            dp[j] = max(dp[j], dp[j-weight[i]] + val[i]); 
    }
    
    cout << dp[cap] << endl;

}


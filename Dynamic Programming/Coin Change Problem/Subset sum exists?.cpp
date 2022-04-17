void solve() {
    int n;
    cin >> n;

    vector<int> v(n+1);
    rep(i, 0, n) cin >> v[i+1];

    int sum = 6;
    vii dp(n+1, vector<bool>(sum+1));
    rep(i, 0, n+1) dp[i][0] = true;

    rep(i, 1, n+1) {
        rep(j, 1, sum+1) {
            if(j < v[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i]];   //every number can use exactly one time thats why dp[i-1][j-v[i]]
                                                             //if use multiple times dp[i][j-v[i]]] while count number of ways
        }
    }

    rep(i, 0, n+1) {
        rep(j, 0, sum+1) cout << dp[i][j] << " ";
        print("");
    }
}

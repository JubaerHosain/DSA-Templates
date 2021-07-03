void solve() {
    int n;
    cin >> n;

    rep(i, 0, n) cin >> a[i];

    pref[0] = a[0], suff[n-1] = a[n-1];
    rep(i, 1, n) pref[i] = __gcd(pref[i-1], a[i]);
    rrep(i, n-2, 0) suff[i] = __gcd(a[i], suff[i+1]);

    int change = a[0];
    int gcd = suff[0];
    rep(i, 0, n) {
        int curr_gcd;
        if(i == 0) 
            curr_gcd = suff[i+1];
        else if(i == n-1) 
            curr_gcd = pref[i-1]; 
        else 
            curr_gcd = __gcd(pref[i-1], suff[i+1]);
        
        if(curr_gcd > gcd) 
            change = a[i], gcd = curr_gcd;
        else if(curr_gcd == gcd)
            change = max(change, a[i]);
    }
}   
 

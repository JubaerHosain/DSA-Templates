vector<ll> a;
vector<ll> x, y;
 
void subset_sum(int n, int s) {
    rep(i, 0, (1<<n)) {
        ll curr = 0;
        rep(j, 0, n) {
            if(i & (1<<j)) curr += a[s+j];
        }
        if(s == 0) x.push_back(curr);
        else y.push_back(curr);
    }
}

//function call
subset_sum(n/2, 0);
subset_sum(n-n/2, n/2);

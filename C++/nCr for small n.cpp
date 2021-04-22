ll nCr(ll n, ll r) {
    ll res = 1;

    rep(i, 0, r) {
        res *= (n-i);
        res /= (i+1);
    }

    return res;
}

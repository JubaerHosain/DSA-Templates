/*************Little Fermat Algorithm*************/
ll fact[N];

void little_fermat() {
    fact[0] = 1;
    rep(i, 1, N-1) {
        fact[i] = (fact[i-1]*i)%p;
    }
}

ll power(ll x, ll n) {
    ll res = 1;

    while(n) {
        if(n%2) {
            res = (res*x)%p;
            n--;
        } else {
            x = (x*x)%p;
            n /= 2;
        }
    }

    return res;
}

ll ncr(ll n, ll r) {
    if(r > n) return 0;
    else if(r == 0) return 1;

    ll ans = fact[n];
    ans = (ans * power(fact[r], p-2))%p;
    ans = (ans * power(fact[n-r], p-2))%p;

    return ans;
}

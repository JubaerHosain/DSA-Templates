ll mod_pow(ll a, ll n, ll p) {
    ll res = 1;

    while(n > 0) {
        if(n&(1LL)) 
            res = (res * a) % p;
        n /= 2;
        a = (a * a) % p;
    }

    return res;
}



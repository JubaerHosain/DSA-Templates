ll mod_pow(ll a, ll n, ll p) {
    ll res = 1;

    while(n) {
        if(n&1) 
            res = (res * a) % p;
        n >>= 1;
        a = (a * a) % p;
    }

    return res;
}

// if there any chance to being n < 0, then change 7th line to n /= 2,
// otherwise it will give TLE

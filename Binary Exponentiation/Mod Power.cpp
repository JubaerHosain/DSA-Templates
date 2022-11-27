ll mod_pow(ll a, ll n, ll p) {
    ll res = 1;

    while(n) {
        if(n&(1L)) 
            res = (res * a) % p;
        n /= 2;
        a = (a * a) % p;
    }

    return res;
}

//===================
ll mod_pow(ll x, ll n, ll p) {
    int res = 1;
    
    while(n) {
        if(n&(1L)) {
            res = (res*x)%p;
            n--;
        } else {
            x = (x*x)%p;
            n /= 2;
        }
    }

    return res;
}


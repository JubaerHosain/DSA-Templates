ll mod_pow(ll x, ll n, ll p) {
    int res = 1;
    
    while(n) {
        if(n&1) {
            res = (res*x)%p;
            n--;
        } else {
            x = (x*x)%p;
            n /= 2;
        }
    }

    return res;
}

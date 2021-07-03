/*
  Efficient solution : Since a and b may be very large numbers, if we try to multiply directly then it will definitely overflow. 
  Therefore we use the basic approach of multiplication i.e.,
  a * b = a + a + … + a (b times) 
*/

ll mod_mul(ll a, ll b, ll p) {
    ll res = 0;
    while(b) {
        if(b&1)
            res = (res + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }

    return res;
}

ll mod_pow(ll a, ll n, ll p) {
    ll res = 1;

    while(n) {
        if(n&1) 
            res = mod_mul(res, a, p);
        n >>= 1;
        a = mod_mul(a, a, p);
    }

    return res;
}

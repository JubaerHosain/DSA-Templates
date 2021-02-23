/*************Binary exponentiation*************/
ll power(ll x, ll n) {
    ll res = 1;
    
    while(n) {
        if(n%2) res *= x, n--;
        else x *= x, n /= 2;
    }

    return res;
}

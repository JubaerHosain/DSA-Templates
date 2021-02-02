/*************nCr%mod Little Fermat Algorithm*************/
const ll N = 2*1e5;
const ull mod = 1e9+7;
ull fac[N+1]; 
void factorial() {                           // It should be initialized first
    fac[0] = 1;
    for(int i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % mod;
}
ull power(ull x, ull y, ull mod) {
    ull res = 1;                             // Initialize result
    x = x % mod;                               // Update x if it is more than or equal to p
    while(y > 0) {
        if (y & 1)                           // If y is odd, multiply x with result
            res = (res * x) % mod;
        y = y >> 1;                          // y = y/2, y must be even now
        x = (x * x) % mod;
    }
    return res;
}   
ull modInverse(ull n, ull mod) {
    return power(n, mod-2, mod);
}  
ull nCrModPFermat(ull n, ull r, ull mod) {
    if(n < r)                               // If n<r, then nCr should return 0
        return 0;
    if(r == 0)                              // Base case
        return 1;
    return (fac[n]*modInverse(fac[r],mod)%mod*modInverse(fac[n-r],mod)%mod)%mod;
}

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(vector<ll> &a) {
    ll ans = a[0];
    for(int i = 1; i < a.size(); i++) 
        ans = (ans*a[i]) / gcd(ans, a[i]);
    return ans;
}  

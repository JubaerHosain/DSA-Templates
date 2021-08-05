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


/////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//not for interactive
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e6+5;
ll factorial[N];

ll mod_pow(ll a, ll b, ll p) {
    ll res = 1;

    while(b) {
        if(b&1)
            res = (res * a) % p;
        b /= 2;
        a = (a * a) % p; 
    }

    return res;
}

void solve() {
    factorial[0] = 1; 
    for(ll i = 1; i < N; i++) 
        factorial[i] = (i * factorial[i-1]) % mod;

    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
    
        ll up = factorial[a];
        ll d1 = mod_pow(factorial[b], mod-2, mod);
        ll d2 = mod_pow(factorial[a-b], mod-2, mod);
        ll ans = (d1 * d2) % mod;
        ans = (up * ans) % mod;
        cout << ans << endl;
    }
    
}

/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cout << fixed << showpoint;
    cout << setprecision(16);

    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }

    return 0;
} 

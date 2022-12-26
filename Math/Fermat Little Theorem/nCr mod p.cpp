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

ll mod_pow(ll a, ll b) {
    ll res = 1;

    while(b) {
        if(b&1)
            res = (res * a) % mod;
        b /= 2;
        a = (a * a) % mod; 
    }

    return res;
}

ll nCr(ll n, ll r) {
	if(n < r)
        return 0;

    ll num = factorial[n];
	ll dnum = (factorial[r]*factorial[n-r])%mod;
    return (num * mod_pow(dnum, mod-2)) % mod;
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
    
        cout << nCr(a, b) << endl;
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

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(v)   v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

const int mod = 1e9+7;
const int N = 1e5+5;
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


void solve_problem() {
    int n, z;
    cin >> n >> z;

	if(n == 1) {
		cout << z << endl;
		return;
	} else if(z < n) {
		cout << 0 << endl;
		return;
	}

	// confirming first number, find all multiples of it
	// all multiple will always give same reminder after suffiling

    ll ans = 0;
    for(int i = 1; i <= z; i++) {
		ll cnt = z/i;
        ll curr = nCr(cnt-1, n-1);
		if(curr <= 0)
			break;
        ans = (ans + curr) % mod;
    }

    cout << ans << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(15);

    factorial[0] = 1;
    for(ll i = 1; i < N; i++)
        factorial[i] = (factorial[i-1]*i)%mod;
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();

    return 0;
} 




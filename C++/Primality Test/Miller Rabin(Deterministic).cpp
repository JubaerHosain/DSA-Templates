#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

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

bool is_composit(ll n, ll a, ll d, int s) {
    ll x = mod_pow(a, d, n);
    if(x == 1 || x == n-1)
        return false;
    for(int r = 1; r < s; r++) {
        x = mod_mul(x, x, n);
        if(x == n-1)
            return false;
    }
    return true;
}

bool miller_rabin(ll n) {
    if(n <= 4) 
        return n == 2 || n == 3;

    int s = 0;
    ll d = n-1;
    while((d&1) == 0) {
        d >>= 1;
        s += 1;
    }

    for(int a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(n == a)
            return true;
        if(is_composit(n, a, d, s))
            return false;
    }

    return true;
}

void solve_problem() {
    ll n;
    cin >> n;

    if(miller_rabin(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

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
    cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

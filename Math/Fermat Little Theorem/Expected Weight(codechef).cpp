#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
ll mod = 998244353;

ll mod_pow(ll a, ll n, ll p) {
    ll res = 1;

    while(n) {
        if(n&1) 
            res = (res * a) % p;
        n >>= 1;
        a = (a * a) % p;
    }

    return res;
}

void solve_problem() {
    ll n;
    cin >> n;

    ll numer = (n * (n+1)) / 2;
    numer %= mod;

    if(n%2 == 0) {
        numer *= (n+1);
        numer %= mod;
        numer *= mod_pow(2, mod-2, mod);
    }
    else {
        numer *= ((n+1)/2);
    }

    numer %= mod;
    cout << numer << endl;
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

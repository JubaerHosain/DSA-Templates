#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

// O(sqrt(N)) time complexity
// euler totient function
ll phi_func(ll n) {
    ll res = n;
    for(ll i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            res /= i;
            res *= (i-1);
            while(n%i == 0)
                n /= i;
        }
    }

    if(n > 1) {
        res /= n;
        res *= (n-1);
    }

    return res;
}

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
    ll p = 5, q = 41;
    ll n = p*q;
    ll phi = (p-1) * (q-1);
    ll e = 2;
    while(e < phi) {
        if(__gcd(e, phi) == 1) 
            break;
        else
            e += 1;
    }

    // de = 1 mod phi
    // d = e^(-1) mod phi
    // simplifies using euler totient function
    ll d = mod_pow(e, phi_func(phi)-1, phi);
 
//     e = public key, d = private key
//     encrypted by receiver public key, decrepted by receiver private key

    // here shown for only 20 integer 
    for(int i = 2323; i <= 2343; i++) {
        ll data = i;
        ll enc = mod_pow(data, e, n);
        ll dec = mod_pow(enc, d, n);

        // if n < data, then this is happen 
        while(dec < data) dec += n;

        cout << "Input data: " << data << endl;
        cout << "Encripted data: " << enc << endl;
        cout << "Decripted data: " << dec << endl;
        cout << endl;
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
    cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

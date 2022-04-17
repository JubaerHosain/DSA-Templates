#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
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
    // both person will be agree upon with public value p and a
    ll p = 23;  // prime number p.
    ll a = 9;   // a is the primetive root of p

    ll xA = 7;  // person A choses private key xA
    ll yA = mod_pow(a, xA, p);  // person A generated public key yA

    ll xB = 8;  // person B choses private key xB
    ll yB = mod_pow(a, xB, p);  // person B generated public key yB

    // generating the secrete key after exchanging the public key yA and yB
    ll keyA = mod_pow(yB, xA, p);
    ll keyB = mod_pow(yA, xB, p);

    cout << "keyA: " << keyA << endl;
    cout << "keyB: " << keyB << endl;
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
    // cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

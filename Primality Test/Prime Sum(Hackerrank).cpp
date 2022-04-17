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

bool is_prime(ll n, int it = 5) {
    if(n <= 4)
        return n == 2 || n == 3;

    for(int i = 0; i < it; i++) {
        ll a = 2 + rand() % (n-3);
        ll res = mod_pow(a, n-1, n);
        if(res != 1)
            return false;
    }

    return true;
}

void solve_problem() {
//     is_prime(n); based on fermat primality test 
  
    ll n, k;
    cin >> n >> k;

    if(n < 2*k) {
        cout << "No" << endl;
        return;
    }

    if(k == 1) {
        if(is_prime(n)) 
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } 
    else if(k == 2) {
        if(n%2 == 0) {
            cout << "Yes" << endl;
        }
        else {
            if(is_prime(n-2)) 
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            }
    }
    else {
        cout << "Yes" << endl;
    }
}

/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    // #endif
 
    cout << fixed << showpoint; 
    cout << setprecision(16);
 
    int test = 1;   
    cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

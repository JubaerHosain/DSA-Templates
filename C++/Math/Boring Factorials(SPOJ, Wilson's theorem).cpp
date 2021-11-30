#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int inf = 1e9;
const int N = 3e5+5;

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
    ll n, p;
    cin >> n >> p;

    if(n >= p) {
        cout << 0 << endl;
        return;
    }

    ll ans  = p-1;
    for(ll i = n+1; i < p; i++)
        ans =  (ans * mod_pow(i, p-2, p)) % p;
    cout << ans%p << endl;
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

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

ll CRT(vector<pair<ll, ll>> &array) {
    ll ans = 0;
    ll n = array.size();

    ll mod = 1;
    for(auto it: array) 
        mod *= it.first;

    for(int i = 0; i < n; i++) {
        ll temp = 1;
        ll p = array[i].first;
        for(int j = 0; j < i; j++) {
            temp = (temp*array[j].first) % mod;
            temp = (temp*mod_pow(array[j].first, p-2, p)) % mod;
        }
        ans += ((array[i].second-ans+mod) * temp) % mod;
        ans = ans % mod;
    }

    return ans;
}

void solve_problem() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        cin >> a[i].second;
    }

    // if a[i].first < 2 then don't use 
    // mod_pow(num, p-2, p) for mod inverse of num

    cout << CRT(a) << endl;
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

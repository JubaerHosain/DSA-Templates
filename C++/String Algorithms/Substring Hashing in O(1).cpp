#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
int mod = 1e9+9;
const int N = 5e2+5;
ll hash_val[N], inverse[N];

ll mod_pow(ll x, ll n, ll mod) {
    ll ans = 1;

    while(n) {
        if(n%2)
            ans = (ans * x) % mod;
        n /= 2;
        x = (x * x) % mod;
    }

    return ans;
}

ll substring_hash(int l, int r) {
    ll ans = hash_val[r];

    if(l > 0)
        ans -= hash_val[l-1];

    return (ans * inverse[l]) % mod;
}

void solve_task() {
    string text;
    cin >> text;

    //pre-process
    ll p = 31, power_p = 1;
    for(int i = 0; i < text.size(); i++) {
        inverse[i] = mod_pow(power_p, mod-2,  mod);
        hash_val[i] = ((text[i]-'a'+1) * power_p) % mod;
        power_p = (power_p * p) % mod;

        if(i > 0) 
            hash_val[i] = (hash_val[i-1] + hash_val[i]) % mod;
    }
    
    cout << substring_hash(0, 1) << endl;
    cout << substring_hash(3, 5) << endl;
    cout << substring_hash(0, 8) << endl;
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
        solve_task();
    }

    return 0;
} 

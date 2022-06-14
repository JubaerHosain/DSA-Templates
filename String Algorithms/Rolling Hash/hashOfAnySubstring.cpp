#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

const int N = 1e6+5;
const int mod = 1e9+9;
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

void pre_process(string &text) {
    ll p = 31, power_p = 1;

    for(int i = 0; i < text.size(); i++) {
        inverse[i] = mod_pow(power_p, mod-2,  mod);
        hash_val[i] = ((text[i]-'a'+1) * power_p) % mod;
        power_p = (power_p * p) % mod;

        if(i > 0) 
            hash_val[i] = (hash_val[i-1] + hash_val[i]) % mod;
    }
}

ll substring_hash(int l, int r) {
    ll ans = hash_val[r];

    if(l > 0)
        ans = (ans - hash_val[l-1] + mod) % mod;

    return (ans * inverse[l]) % mod;
}

/*****main function*****/
int main() {
    string text;
    cin >> text;

    pre_process(text);

    cout << "n = " << text.size() << endl;

    while(true) {
        int l, r;
        cin >> l >> r;
        cout << substring_hash(l, r) << endl;
    }

    return 0;
} 
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
        n /= 2;
        a = (a * a) % p;
    }
    return res;
}

vector<ll> prime_factors(ll n) {
    vector<ll> fts;
    for(ll i = 2; i*i <= n; i++) {
        int cnt = 0;
        while(n%i == 0) {
            cnt++;
            n /= i;
        }
        if(cnt > 0) fts.push_back(i);
    }
    if(n > 1)
        fts.push_back(n);

    return fts;
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
    //this code is not proved by running


    ll x = 35987, r;
    cout << 1 << " " << x << endl;
    fflush(stdout);

    cin >> r;

    ll val = x*x - r;
    vector<ll> pfact = prime_factors(val);

    if(pfact.size() == 1) {
        cout << pfact[0] << endl;
        return;
    }

    sort(pfact.begin(), pfact.end());

    set<ll> set;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < pfact.size(); i++) {
        for(ll j = 0; ; j++) {
            ll rem = j%pfact[i];
            if(set.count(rem) == 0) {
                set.insert(rem);
                v.push_back({pfact[i], j});
                break;
            }
        }
    }

    ll X = CRT(v);

    for(int i = 0; i < v.size(); i++) 
        assert(X%v[i].first == v[i].second);

    cout << 1 << " " << X << endl;
    fflush(stdout);

    ll rem;
    cin >> rem;
    assert(rem > 0);


    for(auto it: v) {
        if((X*X)%it.first == rem) {
            cout <<  2 << " " << it.first << endl;
            fflush(stdout);
            string str;
            cin >> str;
        }
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
    // cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

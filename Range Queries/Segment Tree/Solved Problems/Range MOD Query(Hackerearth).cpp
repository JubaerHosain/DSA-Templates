#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(v)   v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
vector<ll> tree(4*N, 0);

ll mod_pow(ll a, ll n, ll p) {
    ll ans = 1;
    while(n) {
        if(n&(1L))
            ans = (ans * a) % p;
        a = (a * a) % p;
        n /= 2;
    }
    return ans;
}

ll buildST(int i, int l, int r, string &s) {
    if(l == r) {
        int n = s.length();
        if(s[l] == '1')
            tree[i] = mod_pow(2, n-l-1, mod); 
        else 
            tree[i] = 0;
        return tree[i];
    }
    int mid = (l + r) / 2;
    return tree[i] = (buildST(2*i+1, l, mid, s) + buildST(2*i+2, mid+1, r, s)) % mod;
}

ll range_sum(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)       // total overlap
        return tree[i];
    else if(sl > r || sr < l)    // no overlap;
        return 0;
    int mid = (sl + sr) / 2;
    return (range_sum(2*i+1, sl, mid, l, r) + range_sum(2*i+2, mid+1, sr, l, r)) % mod;
}

void update(int i, int l, int r, int pos, string &s) {
    if(l == r) {                 // update in leaf node
        int n = s.length();
        if(s[l] == '1')
            tree[i] = 0;
        else 
            tree[i] = mod_pow(2, n-l-1, mod); 
        s[pos] = s[pos] == '1' ? '0' : '1';
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid)
        update(2*i+1, l, mid, pos, s);
    else
        update(2*i+2, mid+1, r, pos, s);
    tree[i] = (tree[2*i+1] + tree[2*i+2]) % mod;
}

void solve_problem() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    buildST(0, 0, n-1, s);

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int pos; 
            cin >> pos;
            --pos;
            update(0, 0, n-1, pos, s);
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            ll sum = range_sum(0, 0, n-1, l, r);
            ll div = mod_pow(2, n-r-1, mod);
            ll ans = (sum * mod_pow(div, mod-2, mod)) % mod;
            cout << ans << endl;
        }
    }
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(15);

    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 




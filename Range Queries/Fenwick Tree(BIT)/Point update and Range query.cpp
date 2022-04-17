/*
    1. For index i, i is responsible for 2^LSB number below it including this.
    thats why while counting prefix sum i = i - LSB(i). LSB(i) returns the value of
    2^LSB;
    2. For index i its upper index is i = i + LSB(i). so for updating index i, we should
    update all of its uppder index's.
    3. BIT stores the values in prefix sum manner
    4. Fenwick tree is 1 indexing

    Here, LSB(i) = i & -i;
*/

#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 2e5+5;
ll a[N], fen[N];

void update(int i, int diff, int n) {
    while(i <= n) {
        fen[i] += diff;
        i = i + (i & (-i));
    }
}

ll prefix_sum(int i) {
    ll sum = 0;
    while(i > 0) {
        sum += fen[i];
        i = i - (i & (-i));
    }

    return sum;
}

ll range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l-1);
}

void solve() {
    int n, q;
    cin >> n >> q;

    rep(i, 1, n) cin >> a[i];

    //preporcessing BIT
    rep(i, 1, n) update(i, a[i], n);

    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int i, u;
            cin >> i >> u;
            int diff = u - a[i];
            a[i] = u;
            update(i, diff, n);
        } else {
            int l, r;
            cin >> l >> r;
            print(range_sum(l, r));
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
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 

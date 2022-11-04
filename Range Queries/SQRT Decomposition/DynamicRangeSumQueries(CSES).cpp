#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*************User defined function*************/
int seg_size;
vector<ll> segment(1000);

void build_sqrt(vector<int> &a, int n) {
    seg_size = sqrt(n);
    int curr_seg = -1;
    for(int i = 0; i < n; i++) {
        if(i%seg_size == 0)
            curr_seg += 1;
        segment[curr_seg] += a[i];
    }
}

void update(vector<int> &a, int i, int val) {
    int seg_no = i / seg_size;
    segment[seg_no] -= a[i];
    segment[seg_no] += val;
    a[i] = val;
}

ll get_sum(vector<int> &a, int l, int r) {
    ll sum = 0;

    // loop the first segment
    // until we reach r or a starting index of next segment
    while(l < r && l%seg_size != 0) 
        sum += a[l++];

    // loop until we reach segment that contains r
    while(l + seg_size <= r) {
        sum += segment[l/seg_size];
        l += seg_size;
    }

    // loop until r
    while(l <= r) 
        sum += a[l++];

    return sum;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    build_sqrt(a, n);

    while(q--) {
        int t; cin >> t;
        if(t == 1) {    
            int i, val;
            cin >> i >> val;
            update(a, i-1, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << get_sum(a, l-1, r-1) << endl;
        }
    }
} 
 
/*************main function*************/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
}

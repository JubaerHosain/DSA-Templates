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
vector<int> segment(1000, INT_MAX);

void build_sqrt(vector<int> &a, int n) {
    seg_size = sqrt(n);
    int curr_seg = -1;
    for(int i = 0; i < n; i++) {
        if(i%seg_size == 0)
            curr_seg += 1;
        segment[curr_seg] = min(segment[curr_seg], a[i]);
    }
}

int get_min(vector<int> &a, int l, int r) {
    int mn = INT_MAX;

    // loop the first segment
    // until we reach r or a starting index of next segment
    while(l < r && l%seg_size != 0) 
        mn = min(mn, a[l++]);

    // loop until we reach segment that contains r
    while(l + seg_size <= r) {
        mn = min(mn, segment[l/seg_size]);
        l += seg_size;
    }

    // loop until r
    while(l <= r) 
       mn = min(mn, a[l++]);

    return mn;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    build_sqrt(a, n);

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << get_min(a, l-1, r-1) << endl;
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

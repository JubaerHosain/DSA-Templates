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
int a[N];
ll tree[4*N], lazy[4*N];

ll buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = a[l];
    
    int mid = (l + r) / 2;
    return tree[i] = buildST(2*i+1, l, mid) + buildST(2*i+2, mid+1, r);
}

ll get_sum(int i, int sl, int sr, int l, int r) {
    if(lazy[i] != 0) {              //update pending nodes
        tree[i] += lazy[i] * (sr-sl+1);

        if(sl != sr) 
            lazy[2*i+1] += lazy[i], lazy[2*i+2] += lazy[i];

        lazy[i] = 0;
    }

    if(sl >= l && sr <= r)          // total overlap
        return tree[i];
    else if(sr < l || r < sl)       // no overlap;
        return 0;

    int mid = (sl + sr) / 2;
    return get_sum(2*i+1, sl, mid, l, r) + get_sum(2*i+2, mid+1, sr, l, r);
}

void range_update(int i, int sl, int sr, int l, int r, int val) {
    if(lazy[i] != 0) {              //update pending nodes
        tree[i] += lazy[i] * (sr-sl+1);

        if(sl != sr) 
            lazy[2*i+1] += lazy[i], lazy[2*i+2] += lazy[i];

        lazy[i] = 0;
    }

    if(sr < l || r < sl)            // no overlap;
        return;
    
    if(sl >= l && sr <= r) {        // total overlap, update by curr val
        ll curr = val;
        tree[i] += curr * (sr-sl+1);

        if(sl != sr) 
            lazy[2*i+1] += val, lazy[2*i+2] += val;
        
        return;
    }
    
    int mid = (sl + sr) / 2;
    range_update(2*i+1, sl, mid, l, r, val);
    range_update(2*i+2, mid+1, sr, l, r, val);
    
    tree[i] = tree[2*i+1] + tree[2*i+2];  //update intermediate nodes after returning the value of the leaf node
}

ll get_sum(int l, int r, int n) {
    return get_sum(0, 0, n-1, l, r);
}

void range_update(int l, int r, int diff, int n) {
    range_update(0, 0, n-1, l, r, diff);
}


void solve() {
    int n, q;
    cin >> n >> q;

    rep(i, 0, n-1) cin >> a[i];

    //Preprocessing
    //I used 0 based indexing
    buildST(0, 0, n-1);

    while(q--) {
        int x;
        cin >> x;
        if(x == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            --l, --r;
            range_update(l, r, val, n);
        } else {
            int pos;
            cin >> pos;
            --pos;
            print(get_sum(pos, pos, n));
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

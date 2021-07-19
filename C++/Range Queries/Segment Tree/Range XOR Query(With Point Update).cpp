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
ll inf = 1e18;
const int N = 2e5+5;
vector<int> a(N);
vector<ll> tree(4*N);

int buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = a[l];
    
    int mid = (l + r) / 2;
    return tree[i] = buildST(2*i+1, l, mid) ^ buildST(2*i+2, mid+1, r);
}

int get_xor(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)          // total overlap
        return tree[i];
    else if(sr < l || r < sl)       // no overlap;
        return 0;

    int mid = (sl + sr) / 2;
    return get_xor(2*i+1, sl, mid, l, r) ^ get_xor(2*i+2, mid+1, sr, l, r);
}

void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {                      //update in the leaf node of the tree
        tree[i] = val;
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else 
        update(2*i+2, mid+1, sr, pos, val);
    
    tree[i] = tree[2*i+1] ^ tree[2*i+2];  //update intermediate nodes after returning the value of the leaf node
}

int get_xor(int l, int r, int n) {
    return get_xor(0, 0, n-1, l, r);
}

void update(int pos, int val, int n) {
    a[pos] = val;
    update(0, 0, n-1, pos, val);
}

void solve() {
    int n, q;
    cin >> n >> q;

    rep(i, 0, n-1) cin >> a[i];

    //preporcessing SegTree
    //i used 0 indexing seg tree
    buildST(0, 0, n-1);

    while(q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        print(get_xor(l, r, n));
        
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

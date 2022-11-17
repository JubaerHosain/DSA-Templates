#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
struct Node {
    int lazy;
    int zero, one, two;
    Node() {
        lazy = zero = one = two = 0;
    }
};

const int N = 2e5+5;
Node tree[4*N];

ll buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i].zero = 1;
    int mid = (l + r) / 2;
    return tree[i].zero = buildST(2*i+1, l, mid) + buildST(2*i+2, mid+1, r);
}

void rotate(int i) {
    int tmp = tree[i].zero;
    tree[i].zero = tree[i].two;
    tree[i].two = tree[i].one;
    tree[i].one = tmp;
}

void pending_update(int i, int sl, int sr) {
    for(int c = 0; c < tree[i].lazy; c++) 
        rotate(i);
    
    if(sl != sr) {             //update child nodes and reset parent (i)
        int lc = 2*i+1, rc = 2*i+2;
        tree[lc].lazy += tree[i].lazy;
        tree[lc].lazy %= 3;
        tree[rc].lazy += tree[i].lazy;
        tree[rc].lazy %= 3;
    }
        
    tree[i].lazy = 0;
}

void range_update(int i, int sl, int sr, int l, int r, int val) {
    pending_update(i, sl, sr);

    if(sr < l || r < sl)       // no overlap;
        return;

    if(sl >= l && sr <= r)  {     // total overlap
        tree[i].lazy += val;
        pending_update(i, sl, sr);
        return;
    }

    int mid = (sl + sr) / 2;
    range_update(2*i+1, sl, mid, l, r, val);
    range_update(2*i+2, mid+1, sr, l, r, val);
    
    //update intermediate nodes after returning the value of the leaf node
    tree[i].zero = tree[2*i+1].zero + tree[2*i+2].zero;  
    tree[i].one = tree[2*i+1].one + tree[2*i+2].one;  
    tree[i].two = tree[2*i+1].two + tree[2*i+2].two;  
}

ll query(int i, int sl, int sr, int l, int r) {
    pending_update(i, sl, sr);
    
    if(sl >= l && sr <= r)          // total overlap
        return tree[i].zero;
    else if(sr < l || r < sl)       // no overlap;
        return 0;

    int mid = (sl + sr) / 2;
    return query(2*i+1, sl, mid, l, r) + query(2*i+2, mid+1, sr, l, r);
    
}
 
void solve() {
    int n, q;
    cin >> n >> q;

    // preprocess, 0 indexing
    // initially all values are zero
    buildST(0, 0, n-1);

    while(q--) {
        int type;
        cin >> type;
        if(type == 0) {
            int l, r;
            cin >> l >> r;
            range_update(0, 0, n-1, l, r, 1);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n-1, l, r) << endl;
        }
    }
} 
 
/*****main function*****/
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

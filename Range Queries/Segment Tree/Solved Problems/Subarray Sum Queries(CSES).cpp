#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
struct Node {
    long long sum, max, left, right;
};

ll inf = 1e18;
const int N = 2e5+5;
vector<int> a(N);
Node tree[4*N];  

void buildST(int i, int l, int r) {
    if(l == r) {
        tree[i].sum = a[l];
        tree[i].max = max(0, a[l]);
        tree[i].left = max(0, a[l]);
        tree[i].right = max(0, a[l]);
        return;
    }

    int mid = (l + r) / 2;
    buildST(2*i+1, l, mid);
    buildST(2*i+2, mid+1, r);

    int lc = 2*i+1, rc = 2*i+2;
    tree[i].sum = tree[lc].sum + tree[rc].sum;
    tree[i].left = max(tree[lc].left, tree[lc].sum + tree[rc].left);
    tree[i].right = max(tree[rc].right, tree[rc].sum + tree[lc].right);
    tree[i].max = max({tree[lc].max, tree[rc].max, tree[lc].right + tree[rc].left});
}

void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {
        tree[i].sum = val;
        tree[i].max = max(0, val);
        tree[i].left = max(0, val);
        tree[i].right = max(0, val);
        return;
    }

    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else    
        update(2*i+2, mid+1, sr, pos, val);

    int lc = 2*i+1, rc = 2*i+2;
    tree[i].sum = tree[lc].sum + tree[rc].sum;
    tree[i].left = max(tree[lc].left, tree[lc].sum + tree[rc].left);
    tree[i].right = max(tree[rc].right, tree[rc].sum + tree[lc].right);
    tree[i].max = max({tree[lc].max, tree[rc].max, tree[lc].right + tree[rc].left});
}

void update(int pos, int val, int n) {
    a[pos] = val;
    update(0, 0, n-1, pos, val);
}

void solve() {
    int n, q;
    cin >> n >> q;

    rep(i, 0, n-1) cin >> a[i];

    buildST(0, 0, n-1);

    while(q--) {
        int pos, val;
        cin >> pos >> val;
        --pos;
        update(pos, val, n); 
        print(max(0LL, tree[0].max));
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

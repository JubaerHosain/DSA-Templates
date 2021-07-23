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
ll inf = 1e18;
const int N = 2e5+5;
vector<int> a(N);
vector<pii> tree(4*N);  //{sum, prefix_sum}

void buildST(int i, int l, int r) {
    if(l == r) {
        tree[i] = {a[l], a[l]};
        return;
    }

    int mid = (l + r) / 2;
    buildST(2*i+1, l, mid);
    buildST(2*i+2, mid+1, r);

    tree[i].first = tree[2*i+1].first + tree[2*i+2].first;
    tree[i].second = max(tree[2*i+1].second, tree[2*i+1].first + tree[2*i+2].second);
}

pii max_pref(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)      //total overlap
        return tree[i];
    else if(l > sr || r < sl)   //no overlap
        return {0, 0};
    
    int mid = (sl + sr) / 2;
    pii a = max_pref(2*i+1, sl, mid, l, r);
    pii b = max_pref(2*i+2, mid+1, sr, l, r);

    return {a.first+b.first, max(a.second, a.first + b.second)};
}

void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {
        tree[i] = {val, val};
        return;
    }

    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else    
        update(2*i+2, mid+1, sr, pos, val);

    tree[i].first = tree[2*i+1].first + tree[2*i+2].first;
    tree[i].second = max(tree[2*i+1].second, tree[2*i+1].first + tree[2*i+2].second);
}

pii max_pref(int l, int r, int n) {
    return max_pref(0, 0, n-1, l, r);
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
        int t;
        cin >> t;
        if(t == 1) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            update(pos, val, n); 
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            print(max(0LL, max_pref(l, r, n).second));
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

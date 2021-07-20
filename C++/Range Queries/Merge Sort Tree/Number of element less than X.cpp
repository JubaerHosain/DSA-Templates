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
vector<int> a(N);
vector<int> tree[N];

void merge(vector<int> &res, vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;

    //a and b both are soted vector
    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) 
            res.push_back(a[i]), i++;
        else 
            res.push_back(b[j]), j++;
    }

    while(i < a.size())
        res.push_back(a[i]), i++;

    while(j < b.size())
        res.push_back(b[j]), j++;
}

void buildMST(int i, int l, int r) {
    if(l == r) {
        tree[i].push_back(a[l]);
        return;
    }

    int mid = (l + r) / 2;
    buildMST(2*i+1, l, mid);
    buildMST(2*i+2, mid+1, r);

    merge(tree[i], tree[2*i+1], tree[2*i+2]);
}

int query(int i, int sl, int sr, int l, int r, int x) {
    if(sr < l || r < sl)               // no overlap;
        return 0;
    else if(sl >= l && sr <= r)        // total overlap
        return lower_bound(all(tree[i]), x) - tree[i].begin();

    int mid = (sl + sr) / 2;
    return query(2*i+1, sl, mid, l, r, x) + query(2*i+2, mid+1, sr, l, r, x);
}

int query(int l, int r, int n, int x) {
    return query(0, 0, n-1, l, r, x);
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 0, n-1) cin >> a[i];

    //preprocess merge sort tree
    //0 based indexing
    buildMST(0, 0, n-1);

    //query = number of element strictly less than x on range (l, r)
    while(m--) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        print(query(l, r, n, x));
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

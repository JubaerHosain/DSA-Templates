#include<bits/stdc++.h>
using namespace std;
#define all(v)                  v.begin(), v.end()
#define endl                    '\n'//in interactive problem should not use this
#define print(var)              cout << var << endl
#define out(a, b)               cout << a << " " << b << endl
#define rep(i, s, n)            for(int i = s; i < n; i++)
#define rrep(i, n, s)           for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int N = 2e5+5;

/*************Range Maximum Query*************/
vector<int> a(N);
vector<int> tree(4*N);

int buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = a[l];
    
    int mid = (l + r) / 2;
    return tree[i] = max(buildST(2*i+1, l, mid), buildST(2*i+2, mid+1, r));
}

int get_max(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)          // total overlap
        return tree[i];
    else if(sr < l || r < sl)       // no overlap;
        return INT_MIN;

    int mid = (sl + sr) / 2;
    return max(get_max(2*i+1, sl, mid, l, r), get_max(2*i+2, mid+1, sr, l, r));
}

int get_max(int l, int r, int n) {
    return get_max(0, 0, n-1, l, r);
}

/*************User defined function*************/
void solve() {
    int n;
    cin >> n;

    rep(i, 0, n) cin >> a[i];

    //must have to call buildST first
    //root of the tree is 0'th index
    buildST(0, 0, n-1);

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        print(get_max(l, r, n));
    }
} 

/*************main function*************/
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

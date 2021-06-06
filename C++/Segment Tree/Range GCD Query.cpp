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

/*************User defined function*************/
const int N = 1e5+5;
vector<int> a(N);
vector<int> tree(4*N);

int buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = a[l];

    int mid = (l + r) / 2;
    return tree[i] = __gcd(buildST(2*i+1, l, mid), buildST(2*i+2, mid+1, r));
}

int get_gcd(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)              //total overlap
        return tree[i];
    else if(sr < l || sl > r)           //partial overlap
        return 0;

    int mid = (sl + sr) / 2;
    return __gcd(get_gcd(2*i+1, sl, mid, l, r), get_gcd(2*i+2, mid+1, sr, l, r));
}

void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {                                  //update in the leaf node of the tree
        tree[i] = val;
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else 
        update(2*i+2, mid+1, sr, pos, val);
    
    tree[i] = __gcd(tree[2*i+1], tree[2*i+2]);      //update intermediate nodes after returning the value of the leaf node
}

int get_gcd(int l, int r, int n) {
    return get_gcd(0, 0, n-1, l, r);
}

void update(int pos, int val, int n) {
    a[pos] = val;
    update(0, 0, n-1, pos, val);
}

void solve() {
    int n;
    cin >> n;

    rep(i, 0, n) cin >> a[i];

    buildST(0, 0, n-1);
    update(0, 15, n);

    print(get_gcd(0, 4, n));
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

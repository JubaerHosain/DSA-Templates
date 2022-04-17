#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*************User defined function*************/
const int N = 1e5+5;
int bsz;
int a[N], block[1000];

void build_sqrt(int n) {
    bsz = sqrt(n);
    
    int i = 0, blk = 0;
    while(i < n) {
        int mn = INT_MAX;
        while(i < n && i < (blk+1)*bsz) 
            mn = min(mn, a[i++]);

        block[blk++] = mn;
    }
}

int get_min(int l, int r) {
    int lb = l / bsz;
    int rb = r / bsz;

    int mn = INT_MAX;
    if(lb == rb) {
        rep(i, l, r+1) 
            mn = min(mn, a[i]);
        return mn;
    }
 
    rep(i, l, (lb+1)*bsz) 
        mn = min(mn, a[i]);
    rep(i, lb+1, rb)
        mn = min(mn, block[i]);
    rep(i, rb*bsz, r+1) 
        mn = min(mn, a[i]);

    return mn;
}

void solve() {
    int n;
    cin >> n;

    rep(i, 0, n) cin >> a[i];

    build_sqrt(n);

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        print(get_min(l, r));
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

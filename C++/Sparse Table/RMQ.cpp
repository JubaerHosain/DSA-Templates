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

/*************Sparse Table of RMQ*************/
const int N = 1e5+5;
int table[N][30];

void build_table(vector<int> a, int n) {
    rep(i, 0, n) table[i][0] = a[i];

    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; (i + (1 << j) - 1) < n; i++) {
            table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
        }
    }
}

int get_min(int l, int r) {
    int j = log2(r-l+1);
    return min(table[l][j], table[r-(1<<j)+1][j]);
}

/*************User defined function*************/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    build_table(a, n);

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

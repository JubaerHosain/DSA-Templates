#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
vector<ll> BIT;

void point_update(int i, int x, int n) {
    while(i <= n) {
        BIT[i] += x;
        i = i + (i & (-i));
    }
}

void range_update(int l, int r, int val, int n) {
    point_update(l, val, n);
    point_update(r+1, -val, n);
}

ll prefix_sum(int i) {
    ll sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i = i - (i & (-i));
    }
    return sum;
}

ll point_query(int i) {
    return prefix_sum(i);
}

void solve_problem() {
    int n, q;
    cin >> n >> q;

    // 1 based indexing
    BIT.resize(n+1, 0);
    vector<int> a(n+1);   
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            range_update(l, r, val, n);
        } else if(t == 2) {
            int i;
            cin >> i;
            cout << point_query(i) + a[i] << endl;
        }
    }
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(5);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();
    
    return 0;
} 

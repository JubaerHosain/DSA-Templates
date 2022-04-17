#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 2e5+5;
const int mod = 998244353;
vector<int> a(N);
vector<ll> tree(4*N, 0);

ll buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = a[l];
    
    int mid = (l + r) / 2;
    return tree[i] = (buildST(2*i+1, l, mid) + buildST(2*i+2, mid+1, r))%mod;
}

ll get_sum(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)          // total overlap
        return tree[i];
    else if(sr < l || r < sl)       // no overlap;
        return 0;

    int mid = (sl + sr) / 2;
    return (get_sum(2*i+1, sl, mid, l, r) + get_sum(2*i+2, mid+1, sr, l, r))%mod;
}

void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {           //update in the leaf node of the tree
        tree[i] = (tree[i] + val)%mod;
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else 
        update(2*i+2, mid+1, sr, pos, val);
    
    tree[i] = (tree[2*i+1] + tree[2*i+2])%mod;  //update intermediate nodes after returning the value of the leaf node
}

ll get_sum(int l, int r, int n) {
    return get_sum(0, 0, n-1, l, r);
}

void update(int pos, int val, int n) {
    update(0, 0, n-1, pos, val);
}


void solve_problem() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    // buildST(0, 0, n-1);

    vector<ll> dp(n);
    for(int i = 0; i < n; i++) {
        ll query = get_sum(0, a[i]-1, N);
        dp[i] = (1 + query) % mod;
        update(a[i], dp[i], N);
    }

    ll ans = 1;
    for(int i = 0; i < n; i++)
        ans = (ans + dp[i]) % mod;

    cout << ans << endl;
}

/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
 
    cout << fixed << showpoint; cout << setprecision(16);
 
    int test = 1;   
    // cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

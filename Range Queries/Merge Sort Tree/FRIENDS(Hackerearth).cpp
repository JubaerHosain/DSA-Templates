#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(v)   v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
vector<vector<int>> ltree, rtree;

void merge(vector<int> &res, vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
	int m = a.size(), n = b.size();

    //a and b both are soted vector
    while(i < m && j < n) {
        if(a[i] < b[j]) 
            res.push_back(a[i]), i++;
        else 
            res.push_back(b[j]), j++;
    }

    while(i < m)
        res.push_back(a[i]), i++;

    while(j < n)
        res.push_back(b[j]), j++;
}

void buildMST(int i, int l, int r, vector<int> &a, vector<vector<int>> &tree) {
    if(l == r) {
        tree[i].push_back(a[l]);
        return;
    }

    int mid = (l + r) / 2;
    buildMST(2*i+1, l, mid, a, tree);
    buildMST(2*i+2, mid+1, r, a, tree);

    merge(tree[i], tree[2*i+1], tree[2*i+2]);
}

int queryL(int i, int sl, int sr, int l, int r, int x, vector<vector<int>> &tree) {
    if(sr < l || r < sl)               // no overlap;
        return 0;
    else if(sl >= l && sr <= r)        // total overlap
        return upper_bound(all(tree[i]), x) - tree[i].begin();

    int mid = (sl + sr) / 2;
    return queryL(2*i+1, sl, mid, l, r, x, tree) + queryL(2*i+2, mid+1, sr, l, r, x, tree);
}

int queryR(int i, int sl, int sr, int l, int r, int x, vector<vector<int>> &tree) {
    if(sr < l || r < sl)               // no overlap;
        return 0;
    else if(sl >= l && sr <= r)        // total overlap
        return lower_bound(all(tree[i]), x) - tree[i].begin();

    int mid = (sl + sr) / 2;
    return queryR(2*i+1, sl, mid, l, r, x, tree) + queryR(2*i+2, mid+1, sr, l, r, x, tree);
}


void solve_problem() {
    int n;
    cin >> n;

    vector<pii> v(n);
    vector<int> L(n), R(n);
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
		l--, r--;
        v[i] = {l, r};
        L[i] = l;
        R[i] = r;
    }

    // concept used from: 
    // Points in Segments (II) LightOJ.cpp
    
    ltree.resize(4*n);
    rtree.resize(4*n);
    for(int i = 0; i < 4*n; i++) {
        ltree[i].clear();
        rtree[i].clear();
    }


    buildMST(0, 0, n-1, L, ltree);
    buildMST(0, 0, n-1, R, rtree);

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        // l less than or equal to i
        int a = queryL(0, 0, n-1, v[i].first, v[i].second, i, ltree);
        // r less than i
        int b = queryR(0, 0, n-1, v[i].first, v[i].second, i, rtree);
        
        // number of ranges contains i
        ans += (a - b);
        
        // minus 1 for itself
        if(i >= v[i].first && i <= v[i].second)
            ans -= 1;
    }

	assert(ans%2 == 0);

    cout << ans / 2 << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();

    return 0;
} 




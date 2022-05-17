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

// Problem Link: https://atcoder.jp/contests/abc157/tasks/abc157_e?lang=en
// It can be solve By Musfiq's editorial.
 
/*****User defined function*****/
const int N = 5e5+5;
string a;
map<char, int> tree[4*N];

map<char, int> merge_map(map<char, int> &m1, map<char, int> &m2) {
    map<char, int> ans;
    for(auto it: m1) {
        ans[it.first] = it.second;
    }

    for(auto it: m2) {
        ans[it.first] += it.second;
    }

    return ans;
}

map<char, int> buildST(int i, int l, int r) {
    if(l == r) {
        tree[i][a[l]] = 1;
        return tree[i];
    }
    
    int mid = (l + r) / 2;
    // return tree[i] = min(buildST(2*i+1, l, mid), buildST(2*i+2, mid+1, r));
    map<char, int> left = buildST(2*i+1, l, mid);
    map<char, int> right = buildST(2*i+2, mid+1, r);
    return tree[i] = merge_map(left, right);
}

map<char, int> get_unique(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)          // total overlap
        return tree[i];
    else if(sr < l || r < sl)       // no overlap;
    {
        map<char, int> mp;
        return mp;
    }

    int mid = (sl + sr) / 2;
    
    //this was my mistake!!!!!
    //return get_unique(left, right);
  
    map<char, int> mp1 = get_unique(2*i+1, sl, mid, l, r);
    map<char, int> mp2 = get_unique(2*i+2, mid+1, sr, l, r);
    map<char, int> ans = merge_map(mp1, mp2);
    return ans;
}

void update(int i, int sl, int sr, int pos, char val, char old) {
    if(sl == sr) { 
        tree[i].clear();                                     //update in the leaf node of the tree
        tree[i][val] = 1;
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val, old);
    else 
        update(2*i+2, mid+1, sr, pos, val, old);
    
    tree[i] = merge_map(tree[2*i+1], tree[2*i+2]);      //update intermediate nodes after returning the value of the leaf node
    // tree[i][old]--;
    // if(tree[i][old] <= 0)
    //     tree[i].erase(old);
}

int get_unique(int l, int r, int n) {
    map<char, int> mp = get_unique(0, 0, n-1, l, r);
    return mp.size();
}

void update(int pos, char val, int n) {
    if(val == a[pos])
        return;
    char old = a[pos];
    a[pos] = val;
    update(0, 0, n-1, pos, val, old);
}

void solve() {
    int n;
    cin >> n;

    cin >> a;

    //preporcessing SegTree
    //i used 0 indexing seg tree
    buildST(0, 0, n-1);

    int q;
    cin >> q;

    while(q--) {
        int t;
        cin >> t;
        // cout << a << endl;

        if(t == 1) {
            int i;
            char ch;
            cin >> i >> ch;
            i--;
            update(i, ch, n);
        }
        else if(t == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get_unique(l, r, n) << endl;
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
    cout << setprecision(5);
 
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 

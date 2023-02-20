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

// Problem Link: https://www.hackerearth.com/challenges/competitive/february-circuits-23-2/algorithm/is-palindrome-2-eb50514b/

/*****User defined function*****/
struct Node {
    char lazy;
    map<char, int> count;
    Node() {
        lazy = '0';
    }
};

vector<Node> tree;

map<char, int> merge_map(map<char, int> &m1, map<char, int> &m2) {
    map<char, int> ans;
    for(auto it: m1) 
        ans[it.first] = it.second;
    
    for(auto it: m2) 
        ans[it.first] += it.second;

    return ans;
}

map<char, int> buildST(int i, int l, int r, string &a) {
    if(l == r) {
        tree[i].count[a[l]] = 1;
        return tree[i].count;
    }
    
    int mid = (l + r) / 2;
    map<char, int> left = buildST(2*i+1, l, mid, a);
    map<char, int> right = buildST(2*i+2, mid+1, r, a);
    return tree[i].count = merge_map(left, right);
}


void pending_update(int i, int sl, int sr) {
    if(tree[i].lazy != '0') {
        char ch = tree[i].lazy;
        tree[i].count.clear();
        tree[i].count[ch] = (sr-sl+1);

        if(sl != sr) {             //update child nodes and reset parent (i)
            tree[2*i+1].lazy = tree[i].lazy;
            tree[2*i+2].lazy = tree[i].lazy;
        }
    }
        
    tree[i].lazy = '0';
}

void range_update(int i, int sl, int sr, int l, int r, char ch) {
    pending_update(i, sl, sr);

    if(sr < l || r < sl)          // no overlap;
        return;

    if(sl >= l && sr <= r)  {     // total overlap
        tree[i].lazy = ch;
        pending_update(i, sl, sr);
        return;
    }

    int mid = (sl + sr) / 2;
    range_update(2*i+1, sl, mid, l, r, ch);
    range_update(2*i+2, mid+1, sr, l, r, ch);
    
    //update intermediate nodes after returning the value of the leaf node
    tree[i].count = merge_map(tree[2*i+1].count, tree[2*i+2].count); 
}

map<char, int> get_count(int i, int sl, int sr, int l, int r) {
    pending_update(i, sl, sr);

    if(sl >= l && sr <= r)          // total overlap
        return tree[i].count;
    else if(sr < l || r < sl) {     // no overlap;
        map<char, int> mp;
        return mp;
    }

    int mid = (sl + sr) / 2;
  
    map<char, int> mp1 = get_count(2*i+1, sl, mid, l, r);
    map<char, int> mp2 = get_count(2*i+2, mid+1, sr, l, r);
    map<char, int> ans = merge_map(mp1, mp2);
    return ans;
}



bool possible(map<char, int> &mp) {
    int odd = 0;
    for(auto it: mp) {
        if(it.second%2 == 1)
            odd += 1;
    }

    return odd <= 1;
}


void solve() {
    string s; 
    cin >> s;

    int n = s.length();
    tree.resize(4*n);

    buildST(0, 0, n-1, s);

    int q;
    cin >> q;

    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;

        if(t == 1) {
            char ch; cin >> ch;
            range_update(0, 0, n-1, l, r, ch);
        } else {
            map<char, int> cnt = get_count(0, 0, n-1, l, r);
            if(possible(cnt)) 
                cout << "Yes" << endl;
            else 
                cout << "No" << endl;
        }
    }
} 
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(5);
 
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 

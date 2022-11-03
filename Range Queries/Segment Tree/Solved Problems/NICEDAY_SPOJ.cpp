#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 4e5+5;
int tree[N];

struct Node {
    int a, b, c;
    Node() {
        a = b = c = 0;
    }
};

int get_min(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)          // total overlap
        return tree[i];
    else if(sr < l || r < sl)       // no overlap;
        return INT_MAX;

    int mid = (sl + sr) / 2;
    return min(get_min(2*i+1, sl, mid, l, r), get_min(2*i+2, mid+1, sr, l, r));
}

void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {                                      //update in the leaf node of the tree
        tree[i] = val;
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else 
        update(2*i+2, mid+1, sr, pos, val);
    
    //update intermediate nodes after returning the value of the leaf node
    tree[i] = min(tree[2*i+1], tree[2*i+2]);               
}

bool cmp(const Node &a, const Node &b) {
    return a.a < b.a;
}

void solve() {
    // 0 indexed segment tree

    fill(tree, tree + N, INT_MAX);

    int n; cin >> n;
    vector<Node> v(n);
    for(int i = 0; i < n; i++) 
        cin >> v[i].a >> v[i].b >> v[i].c;

    // sort by first competetion rank
    sort(all(v), cmp);
    
    int cnt = 0;
    // minimum of second competetion for those who are better in 1st competetion
    int min_b = INT_MAX;
    // minimum of third competetion for those who are better in 1st and 2nd both competetion
    int min_c = INT_MAX;

    for(auto it: v) {
        if(it.b < min_b) {
            cnt += 1;
            min_b = it.b;
        } else {
            min_c = get_min(0, 0, n-1, 0, it.b-1); 
            if(it.c < min_c)
                cnt += 1;
        }
        update(0, 0, n-1, it.b-1, it.c);
    }

    cout << cnt << endl;
} 
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    int t; cin >> t;
    while(t--) solve();
 
    return 0;
} 

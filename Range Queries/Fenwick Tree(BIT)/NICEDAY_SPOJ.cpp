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
const int N = 1e5 + 5;

// index i stores minimum of 1 to i
int tree[N];

struct Node {
    int a, b, c;
    Node() {
        a = b = c = 0;
    }
};

void update(int i, int val, int n) {
    while(i <= n) {
        tree[i] = min(tree[i], val);
        i += (i&(-i));
    }
}

int get_min(int i) {
    int mn = INT_MAX;
    while(i > 0) {
        mn = min(mn, tree[i]);
        i -= (i&(-i));
    }
    return mn;
}

bool cmp(const Node &a, const Node &b) {
    return a.a < b.a;
}

void solve() {
    for(int i = 0; i < N; i++)
        tree[i] = INT_MAX;

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

    // following code also works
    // for(auto it: v) {
    //     min_c = get_min(it.b);
    //     if(it.c < min_c)
    //         cnt += 1;
    //     update(it.b, it.c, n);
    // }

    for(auto it: v) {
        if(it.b < min_b) {
            cnt += 1;
            min_b = it.b;
        } else {
            min_c = get_min(it.b);
            if(it.c < min_c)
                cnt += 1;
        }
        update(it.b, it.c, n);
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

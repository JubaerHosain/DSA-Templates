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

/*****User defined function*****/
const int N = 2e5+5;
int a[N], freq[N];
int bsz = 800, ml, mr, cnt = 0;

struct Node {
    int i, l, r;
};

bool cmp(Node a, Node b) {
    if(a.l/bsz == b.l/bsz)
        return a.r < b.r;
    else 
        return a.l < b.l;
}

void add(int i) {
    freq[a[i]]++;
    if(freq[a[i]] == 1) cnt++;
}

void remove(int i) {
    freq[a[i]]--;
    if(freq[a[i]] == 0) cnt--;
}

void solve() {
    int n, q;
    cin >> n >> q;

    //a[i] is up to 1e9
    //thats why coordinate compression
    int cmpno = 0;
    map<int, int> mp;
    rep(i, 0, n-1) {
        cin >> a[i];
        if(!mp[a[i]]) {
            mp[a[i]] = ++cmpno;
            a[i] = mp[a[i]];
        } else {
            a[i] = mp[a[i]];
        }
    } 

    vector<Node> query;
    rep(i, 0, q-1) {
        int l, r;
        cin >> l >> r;
        query.push_back({i, l-1, r-1});
    }

    //sort by block
    sort(all(query), cmp);

    //why mr = -1?
    ml = 0, mr = -1;
    vector<int> ans(q);
    for(Node it: query) {
        while(it.l > ml) 
            remove(ml), ml++;
        while(it.l < ml)
            ml--, add(ml);

        while(it.r > mr) 
            mr++, add(mr);
        while(it.r < mr)
            remove(mr), mr--;

        ans[it.i] = cnt;
    }

    rep(i, 0, q-1) print(ans[i]);
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
    cout << setprecision(16);
 
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 

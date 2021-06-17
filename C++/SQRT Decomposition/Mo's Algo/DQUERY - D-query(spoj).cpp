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
const int N = 1e6+5;
int a[N], freq[N];
int ml = 0, mr = -1;              //why ml = 0, mr = -1?
int bsz = 700, cnt = 0;
vector<pair<int, pii>> query;     //{i, {l, r}};

bool cmp(pair<int, pii> a, pair<int, pii> b) {
    if(a.second.first/bsz != b.second.first/bsz)
        return a.second.first < b.second.first;
    else 
        return a.second.second < b.second.second;
}

void add(int inx) {
    freq[a[inx]]++;
    if(freq[a[inx]] == 1) 
        cnt++;
}

void remove(int inx) {
    freq[a[inx]]--;
    if(freq[a[inx]] == 0)
        cnt--;
}

void solve() {
    int n;
    cin >> n;

    rep(i, 0, n) cin >> a[i];

    
    int q;
    cin >> q;
    query = vector<pair<int, pii>>(q);
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        query[i] = {i, {l, r}};
    }

    sort(all(query), cmp);

    vector<int> ans(q);
    for(auto it: query) {
        int l = it.second.first;
        int r = it.second.second;

        while(ml > l) 
            ml--, add(ml);
        while(mr < r) 
            mr++, add(mr);

        while(ml < l) 
            remove(ml), ml++;
        while(mr > r) 
            remove(mr), mr--;

        ans[it.first] = cnt;
    }

    for(auto i: ans) print(i);
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

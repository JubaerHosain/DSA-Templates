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
const int N = 1e6+5;
int cnt = 0, a[N], freq[N];
//map<int, int> freq;                //use array if a[i] is small else map
int ml = 0, mr = -1, blsz = 1000;  //why mr = -1

bool cmp(pair<int, pii> &a, pair<int, pii> &b) {
    if(a.second.first/blsz != b.second.first/blsz)
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
    int n, m;
    cin >> n; // >> m;

    rep(i, 0, n-1) cin >> a[i];

    cin >> m;

    //{i, {l, r}}
    vector<pair<int, pii>> q;
    rep(i, 0, m-1) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        q.push_back({i, {l, r}});
    }

    //sort by block
    sort(all(q), cmp);

    vector<int> ans(m);
    for(auto it: q) {
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

    rep(i, 0, m-1) print(ans[i]);
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

#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
int mod = 1e9+7;
int inf = 1e9+5;

// return less element with max count
int get_best(map<int, int> &mp, int ai) {
    auto it = mp.lower_bound(ai);
    if(it == mp.begin())
        return 0;
    return (--it)->second;
}

void insert(map<int, int> &mp, int ai, int cnt) {
    if(mp[ai] >= cnt)
        return;

    mp[ai] = cnt;
    auto it = ++mp.find(ai);
    while(it != mp.end() && it->second <= cnt) {
        auto tmp = it++;
        mp.erase(tmp);
    }
    
//     2 -> 3
//     3 -> 2
//     5 -> 3
    // 2 -> 3 is beneficial, so erase bigger element with less or equal count
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    // finding the maximum size not the actual sequence

    map<int, int> mp;
    vector<int> dp(n);
    dp[0] = mp[a[0]] = 1;
    rep(i, 1, n) {
        dp[i] = 1 + get_best(mp, a[i]);
        insert(mp, a[i], dp[i]);
    }

    print(*max_element(all(dp)));
}

/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

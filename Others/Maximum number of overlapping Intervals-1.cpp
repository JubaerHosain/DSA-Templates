#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//not for interactive
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii; 

/*****User defined function*****/
const int N = 2e5+5;

void solve() {
    int n;
    cin >> n;

    vector<pii> ranges;
    rep(i, 1, n) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({l, r});
    }

    sort(ranges.begin(), ranges.end());

    int cnt = 1;
    priority_queue<int> pq;
    pq.push(-ranges[0].second);
    rep(i, 1, n-1) {
        int mn = -pq.top();
        if(mn <= ranges[i].first)
            pq.pop();
        pq.push(-ranges[i].second);
        cnt = max(cnt, (int)pq.size());
    }

    cout << cnt << endl;
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

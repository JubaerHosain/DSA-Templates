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
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    rep(i, 0, n-1) cin >> a[i];

    ll ans = 0;
    ll low = 1, high = 1e18;
    while(low <= high) { 
        ll tmp = 0;
        ll mid = (low + high) / 2;

        rep(i, 0, n-1) {
            tmp += (mid/a[i]);
            if(tmp >= t) break;   //overflow
        }

        if(tmp >= t) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
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

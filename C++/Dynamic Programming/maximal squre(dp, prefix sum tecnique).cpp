#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforintera
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define out(a, b)     cout << a << " " << b << endl
#define rep(i, s, n)  for(int i = s; i < n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*************User defined function*************/
const int N = 1e3+5;
int dp1[N][N], dp2[N][N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int q = n*m;
    vector<pii> p;
    while(q--) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    int ans = -1;
    int l = 0, r = n*m-1;
    while(l <= r) {
        int mid = (l+r)/2;

        rep(i, 0, n+1) 
        rep(j, 0, m+1)
            dp1[i][j] = 0, dp2[i][j] = 0;

        rep(i, 0, mid+1) {
            if(i%2 == 0) dp1[p[i].first][p[i].second] = 1;
            else dp2[p[i].first][p[i].second] = 1;
        }

        bool found = false;
        rep(i, 1, n+1) rep(j, 1, m+1) {
            // if(dp1[i][j]) {
            //     dp1[i][j] += min(dp1[i-1][j-1], min(dp1[i-1][j], dp1[i][j-1]));
            //     if(dp1[i][j] >= k) 
            //         found = true;
            // }
            
            dp1[i][j] += dp1[i-1][j] + dp1[i][j-1] - dp1[i-1][j-1];
            if(i >= k && j >= k) {
                int cnt = dp1[i][j] - dp1[i-k][j] - dp1[i][j-k] + dp1[i-k][j-k];
                if(cnt == k*k)
                    found = true;
            }
        }

        rep(i, 1, n+1) rep(j, 1, m+1) {
            // if(dp2[i][j]) {
            //     dp2[i][j] += min(dp2[i-1][j-1], min(dp2[i-1][j], dp2[i][j-1]));
            //     if(dp2[i][j] >= k) 
            //         found = true;
            // }

            dp2[i][j] += dp2[i-1][j] + dp2[i][j-1] - dp2[i-1][j-1];
            if(i >= k && j >= k) {
                int cnt = dp2[i][j] - dp2[i-k][j] - dp2[i][j-k] + dp2[i-k][j-k];
                if(cnt == k*k)
                    found = true;
            }
        }

        if(found) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if(ans == -1) print("Draw");
    else if(ans%2 == 0) print("Alice");
    else print("Bob");
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
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}    

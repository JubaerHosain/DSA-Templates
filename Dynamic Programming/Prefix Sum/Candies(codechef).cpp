// https://www.codechef.com/problems/CANDIES3

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(v)   v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

ll get(int l, int r, vector<ll> &psum) {
    return psum[r] - psum[l-1];
}

void solve_problem() {
    int n, m; 
    cin >> n >> m;
   
    vector<ll> freq(m+1, 0), c(m+1);
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        freq[a] += 1;
    }

    for(int i = 1; i <= m; i++) {
        cin >> c[i];
    }

    // psum
    for(int i = 1; i <= m; i++) {
        freq[i] += freq[i-1];
    }

    // for(int i = 1; i <= m; i++) 
    //     cout << freq[i] << " ";
    // cout << endl;

    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        ll tot = 0;
        ll cnt = 1;
        for(int j = i; j <= m; j += i) {
            int r = min(m, j + i - 1);
            // cout << j << " " << r << " " << get(j, r, freq) << endl;
            tot += (cnt * get(j, r, freq));
            cnt += 1;
        }
        ans = max(ans, tot*c[i]);
        // cout << i << " " << tot << endl;
    }

    cout << ans << endl;
}
   
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();

    return 0;
} 




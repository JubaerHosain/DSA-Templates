#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

 
/*****User defined function*****/

void solve_problem() {
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    // gcd of all elements
    ll g = a[0];
    for (int i = 1; i < n; i++) {
        g = __gcd(a[i], g);
    }
 
    // factors of g is also fator/divisor of all element of array
    int cnt = 0;
    for (ll i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            cnt += 1;
            if (g / i != i)
                cnt += 1;
        }
    }
 
    cout << cnt << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(5);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();
    
    return 0;
} 
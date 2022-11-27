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

bool possible(ll n1, ll n2, ll x, ll y, ll lcm, ll n) {
    ll dx = n/x;   // divisible by x
    ll dy = n/y;   // divisible by y
    ll byXY = n / lcm;

    ll onlyX = dx - byXY;
    ll onlyY = dy - byXY;

    n1 -= onlyY;
    n2 -= onlyX;

    ll XorY = dx + dy - byXY;
    ll byNone = n - XorY;

    n1 = n1 < 0 ? 0 : n1;
    n2 = n2 < 0 ? 0 : n2;

    return byNone >= n1 + n2;
}

void solve_problem() {
    ll n1, n2, x, y;
    cin >> n1 >> n2 >> x >> y;

    ll lcm = (x*y)/__gcd(x, y);

    ll ans = 1;
    ll low = 1, high = 1e15;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(possible(n1, n2, x, y, lcm, mid)) {
            ans = mid;
            high = mid - 1;
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
    cout.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();

    return 0;
} 

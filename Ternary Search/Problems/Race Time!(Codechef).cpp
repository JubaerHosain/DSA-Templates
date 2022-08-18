#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

double f(double t, vector<int> &s, vector<int> &d) {
    double mn = INT_MAX, mx = INT_MIN;
    for(int i = 0; i < s.size(); i++) {
        double pi = t*s[i] + d[i];
        mn = min(mn, pi);
        mx = max(mx, pi);
    }
    return mx - mn;
}

void solve_problem() {
    int n, k;
    cin >> n >> k;

    vi s(n), d(n);
    rep(i, 0, n-1) cin >> s[i] >> d[i];

    double l = 0, r = k;
    while(r-l > 1e-9) {
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        double f1 = f(m1, s, d);
        double f2 = f(m2, s, d);
        if(f1 > f2) 
            l = m1;
        else
            r = m2;
    }

    cout << min(f(l, s, d), f(r, s, d)) << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(6);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


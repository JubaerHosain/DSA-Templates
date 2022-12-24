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

void solve_problem(int t) {
    int n, q;
    cin >> n >> q;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
            cin >> l[i] >> r[i];
    
    sort(all(l));
    sort(all(r));

    cout << "Case " << t << ": " << endl;
    while(q--) {
        int x; cin >> x;
        int a = upper_bound(all(l), x) - l.begin();
        int b = lower_bound(all(r), x) - r.begin();
        cout << a - b << endl;
    }
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
    for(int t= 1; t <= test; t++)
        solve_problem(t);

    return 0;
} 



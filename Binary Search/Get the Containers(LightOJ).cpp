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

bool possible(vector<int> a, ll capacity, int m) {
    int cnt = 1;
    ll sum = 0;
    for(int i: a) {
        if(sum+i <= capacity) {
            sum += i;
        } else {
            sum = i;
            cnt += 1;
        }
    }
    return cnt <= m;
}

void solve_problem(int t) {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    
    if(m >= n) {
        cout << "Case " << t << ": " << mx << endl;
        return;
    }
    
    ll low = mx, high = 1e9, ans = 0;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(possible(a, mid, m)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << "Case " << t << ": " << ans << endl;
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
    for(int i = 1; i <= test; i++)
        solve_problem(i);

    return 0;
} 


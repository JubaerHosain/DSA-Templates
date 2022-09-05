

// https://www.spoj.com/problems/EKO/






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

ll get_sum(vector<int> &a, int mid) {
    ll sum = 0;
    for(int i: a) 
        sum += i > mid ? i - mid : 0;
    return sum;
}

void solve_problem() {
    ll n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int low = 0, high = 1e9;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(get_sum(a, mid) >= m) {
            ans = mid;
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
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
    cout << setprecision(15);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


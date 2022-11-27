// link: https://www.hackerearth.com/practice/algorithms/sorting/counting-sort/practice-problems/algorithm/distinct-arithmetic-sequences-5adc076e/

// distinct arithmetic subsequence of length N


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

void solve_problem() {
    int m, n;
    cin >> m >> n;

    int N = m + n;
    vector<int> a(N);
    int mn = INT_MAX, mx = INT_MIN;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    map<int, int> mp;
    for(int i = 0; i < N; i++) {
        mp[a[i]] += 1;
    }

    ll same = 0;
    vector<int> v;   // values of v will be sorted
    for(auto it: mp) {
        v.push_back(it.first);
        // all are same
        if(it.second >= m)
            same += 1;
    }

    N = v.size();
    int MAX = mx;
    if(mn < 0) {
        for(int i = 0; i < N; i++)
            v[i] -= mn;
        MAX -= mn;
    }

       
    /*
        why D = 2*m/(m-1)
        -m <= a[i] <= m
        a, a+d, a+2d....a+(m-1)d
        
        so, a+(m-1)d = m       // as max can be m, a can be -m
        or, (m-1)d = m-a = m+m
        so, d = 2*m/(m-1)
    */
    
    ll ans = 0;
    int D = 2*m/(m-1);   
    for(int d = 1; d <= D; d++) {
        vector<int> dp(N, 1), mp(MAX+1, -1);
        for(int i = 0; i < N; i++) {
            int prev = v[i]-d;
            if(prev >= 0 && mp[prev] != -1)
                dp[i] += dp[mp[prev]];
            mp[v[i]] = i;
            if(dp[i] >= m)
                ans += 1;
        }
    }

    // ans is for increasing, for equivalent decreasing it becomes 2*ans
    cout << 2*ans + same << endl;
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





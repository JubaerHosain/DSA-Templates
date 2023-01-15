// https://codeforces.com/contest/1731/problem/C

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

// count subarrays with xor k
ll count_subarray(vector<int> &pxor, int n, int k) {
    // a[i] <= n so max xor can be at max 2*n
    // k <= 2*n, so N should 4*n
    int N = 4*n + 1;
    vector<int> mp(N, 0);
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        int tmp = pxor[i] ^ k;
        ans += mp[tmp];
        if(pxor[i] == k)
            ans += 1;

        mp[pxor[i]] += 1;
    }
    
    return ans;
}

void solve_problem() {
    ll n;
    cin >> n;

    vector<int> a(n), pxor(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0)
            pxor[i] = a[i];
        else 
            pxor[i] = a[i] ^ pxor[i-1];
    }
    

    ll ans = n * (n+1) / 2;
    ll cnt = 0;
    // only perfect squares have odd number of divisor
    // xor can have at max 2n
    int N = 2*n;
    for(int i = 0; i*i <= N; i++) {
        cnt += count_subarray(pxor, n, i*i);
    }

    cout << ans - cnt << endl;
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



/*
    see gfg for details...
    [........A]
    [...........................B]
    K = A ^ B 
    A = B ^ K
    As, K is given and B is prefix xor at j
    we need a map for counting prefix xor's Ai
*/



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
const int N = 2e5;

void solve_problem() {
    int n, k;
    cin >> n >> k;

    // 1 <= a[i] <= n
    vector<int> a(n), pxor(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0)
            pxor[i] = a[i];
        else 
            pxor[i] = a[i] ^ pxor[i-1];
    }

    // map for prefix xor
    vector<int> mp(N, 0);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int tmp = pxor[i] ^ k;
        ans += mp[tmp];
        if(pxor[i] == k)
            ans += 1;

        mp[pxor[i]] += 1;
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
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 
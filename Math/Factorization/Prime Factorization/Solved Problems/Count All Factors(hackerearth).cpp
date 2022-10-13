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
const int N = 1e7+5;
vector<int> factor(N, -1);
vector<bool> present(N, false);

void factor_sieve() {
    for(int i = 4; i <= N; i += 2) {
        if(factor[i] == -1) factor[i] = 2;
    }

    for(int i = 3; i*i <= N; i += 2) {
        for(int j = 2*i; j <= N; j += i) {
            if(factor[j] == -1) factor[j] = i;
        }
    }
}

void solve_problem() {
    int n; 
    cin >> n;

    for(int i = 0; i < n; i++) {
        int ai; cin >> ai;
        present[ai] = true;
    }

    factor_sieve();

    int q;
    cin >> q;
    while(q--) {
        int k; cin >> k;

        if(k == 1) {
            cout << 0 << endl;
            continue;
        }

        // find (prime factor, count) pair
        map<int, ll> mp; 
        while(factor[k] != -1) {
            int num = factor[k];
            int cnt = 0;
            while(k%num == 0) {
                k /= num;
                cnt += 1;
            }
            mp[num] = cnt;
        }
        if(k > 1) mp[k] = 1;

        ll total = 1;
        for(auto it: mp) 
            total *= (it.second+1);
        
        ll ans = 0;
        // find the contribution of each prime factor
        for(auto it: mp) {
            if(present[it.first]) 
                ans += ((total)/(it.second+1)*it.second);
        }

        cout << ans << endl;
    }
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


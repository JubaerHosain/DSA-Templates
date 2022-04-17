#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

ll total = 1;           // total number of prime factor
map<ll, ll> pfactors;
void prime_factors(ll n) {
    for(ll i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            int cnt = 0;
            while(n%i == 0) {
                n /= i;
                cnt += 1;
            }
            pfactors[i] = cnt;
            total *= (cnt+1);
        }
    }

    if(n > 1) {
        pfactors[n] = 1;
        total *= 2;
    }
}

void solve_problem() {
    ll N, Q;
    cin >> N >> Q;

    prime_factors(N);

    // for(auto it: pfactors) 
    //     cout << it.first << " " << it.second << endl;
    // cout << "==================" << endl;

    while(Q--) {
        ll t, k;
        cin >> t >> k;
        if(t == 1) {
            ll ans = 1;
            for(auto it: pfactors) {
                ll cnt = 0;
                while(k%it.first == 0) {
                    k /= it.first;
                    cnt++;
                }
                ans *= (min(cnt, it.second) + 1);
            }
            cout << ans << endl;
        }
        else {
            ll ans = 1;
            for(auto it: pfactors) {
                ll cnt = 0;
                while(k%it.first == 0) {
                    k /= it.first;
                    cnt++;
                }
                if(cnt > it.second) {
                    ans = 0;
                    break;
                }
                ans *= (it.second - cnt + 1);
            }
            if(k > 1) ans = 0;
            
            if(t == 2)
              cout << ans << endl;
            else 
              cout << total - ans << endl;
        }
    } 
}

/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
 
    cout << fixed << showpoint; 
    cout << setprecision(16);
 
    int test = 1;   
    // cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

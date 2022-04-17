#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
#define endl '\n' //not-for-interactive

/*****User defined function*****/
int mod = 1e9+9;
const int N = 1e6+5;

void rabin_karp(string &text, string &patt) {
    int n = text.size();
    int m = patt.size();

    //p = number of distinct char
    //power_p = mod_pow(p, m-1)
    ll p = 31, power_p = 1;
    for(int i = 0; i < m-1; i++) 
        power_p = (p * power_p) % mod;

    ll text_hash = 0;
    ll patt_hash = 0;
    for(int i = 0; i < m; i++) {
        text_hash = ((text_hash * p) % mod + (text[i] - 'a' + 1)) % mod;
        patt_hash = ((patt_hash * p) % mod + (patt[i] - 'a' + 1)) % mod;
    }

    int j = 0;
    int ans = 0;
    for(int i = 0; i <= n-m; i++) {
        if(text_hash == patt_hash) {
            for(j = 0; j < m; j++) {
                if(text[i+j] != patt[j])
                    break;
            }
            if(j == m)
                ans++;
        }

        if(i < n-m) {
            text_hash = (text_hash - (text[i] - 'a' + 1) * power_p) % mod;
            text_hash = (text_hash * p) % mod;
            text_hash = (text_hash + (text[i+m] - 'a' + 1) + mod) % mod;
        }
    }

    cout << ans << endl;
}

void solve_task() {
    string text, patt;
    cin >> text >> patt;

    rabin_karp(text, patt);
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
    //cin >> test;
    while(test--) {
        solve_task();
    }

    return 0;
} 

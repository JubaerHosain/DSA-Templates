#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//not for interactive
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef pair<int, int> pii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 5e2+5;

void compute_lps(string &pat, vector<int> &lps) {
    int m = pat.size();

    lps[0] = 0;
    int len = 0, i = 1;
    while(i < m) {
        if(pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else {
            if(len != 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }
}

void kmp(string &text, string &pat) {
    int n = text.size();
    int m = pat.size();

    // computing lps
    vector<int> lps(m);
    compute_lps(pat, lps);

    // matching pattern
    int i = 0, j = 0;
    while(i < n) {
        if(text[i] == pat[j]) {
            i++, j++;
        } else {
            if(j != 0)
                j = lps[j-1];
            else 
                i = i + 1;
        }

        if(j == m) {
            cout << "Matched at: " << i - j << endl;
            j = lps[j-1];
        } 
    }
}

void solve() {
    string text, pat;
    cin >> text >> pat;
    
    kmp(text, pat);
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
        solve();
    }

    return 0;
} 

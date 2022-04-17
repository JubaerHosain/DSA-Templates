#include<bits/stdc++.h>
using namespace std;
#define newline '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e5+5;

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

void solve_task() {
    string text, pat;
    cin >> pat >> text;
    
    //text or pat shouldn't contain #
    string search_string = pat +  "#" + text;

    vector<int> lps(search_string.size());
    compute_lps(search_string, lps);

    int ans = 0;
    int m = pat.size();
    int n = search_string.size();
    for(int i = 0; i < n; i++) 
        if(lps[i] == m) ans++;

    cout << ans << newline;   
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

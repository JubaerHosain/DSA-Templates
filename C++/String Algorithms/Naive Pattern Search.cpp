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

void pattern_search(string &text, string &pattern) {
    int n = text.size();
    int m = pattern.size();

    for(int i = 0; i <= n-m; i++) {
        bool matched = true;

        for(int j = 0; j < m; j++) {
            if(text[i + j] != pattern[j])
                matched = false;
        }
        
        if(matched)
            cout << "Mathced at: " << i << endl;
    }
}

void solve() {
    string text, pattern;
    cin >> text >> pattern;
    
    pattern_search(text, pattern);
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

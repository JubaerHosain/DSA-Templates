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

// longest common prefix starting at s[i] and t[j]
 
/*****User defined function*****/

void solve_problem() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    // longest common prefix
    vector<vector<int>> lcp(n+1, vector(m+1, 0));
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(s[i] == t[j]) 
                lcp[i][j] = max(lcp[i][j], 1 + lcp[i+1][j+1]);
        }
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


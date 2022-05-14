#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e5+5;

auto zfunction(string &str) {
    int n = str.size();

    int l = 0, r = 0;
    vector<int> z(n);
    for(int i = 1; i < n; i++) {
        if(i > r) {
            l = i, r = i;
            while(r < n && str[r-l] == str[r])
                r++;
            r--;
            z[i] = r - l + 1;
        } else {
            int j = i - l;
            if(z[j] < r-i+1) {
                z[i] = z[j];
            } else {
                l = i;
                while(r < n && str[r-l] == str[r])
                    r++;
                r--;
                z[i] = r - l + 1;
            }
        }
    }
        
    return z;
}

void solve_task() {
    string text, patt;
    cin >> text >> patt;

    string str = patt + "$" + text;
    auto z = zfunction(str);

    int ans = 0;
    int n = str.size();
    int m = patt.size();
    for(int i = 0; i < n; i++) 
        if(z[i] == m) ans++;
    
    cout << ans << endl;
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

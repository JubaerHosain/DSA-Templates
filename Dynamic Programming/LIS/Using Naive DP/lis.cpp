#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 5e5+5;

void solve_problem() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    vector<int> dp(n, 1);
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < j; i++) {
            if(a[j] > a[i])
                dp[j] = max(dp[j], 1 + dp[i]);
        }
    }

    cout << "Max LIS Length: ";
    cout << *max_element(dp.begin(), dp.end()) << endl;
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
    cout << setprecision(5);
 
    int test = 1;
    //cin >> test;
    while(test--) {
        solve_problem();
    }
 
    return 0;
} 
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

// expected value of an array

void solve_problem() {
    int n = 6;
    vector<int> a = {1, 2, 3, 4, 5, 6};

    double exp_val = 0;

    // equal probability of each number
    double prob = (1/(double)n);

    for(int i = 0; i < n; i++) 
        exp_val += a[i]*prob;

    // same as average
    // sum of 0, n-1 divided by n
    
    cout << "Expected Value: " << exp_val << endl;
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
    cout << setprecision(15);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


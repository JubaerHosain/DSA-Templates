#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
void solve_problem() {
    ll a, b;
    cin >> a >> b;

    if(__gcd(a, b) != 1) 
        cout << -1 << endl;
    else 
        cout << a*b - (a+b-1) << endl;
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
    cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

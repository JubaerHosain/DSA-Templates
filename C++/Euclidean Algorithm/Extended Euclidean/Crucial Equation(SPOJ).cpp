#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
void solve_problem(int t) {
    int a, b, c;
    cin >> a >> b >> c;

    if(c % __gcd(a, b) == 0)
        cout << "Case " << t << ": Yes" << endl;
    else
        cout << "Case " << t << ": No" << endl;
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
    int t = 1;
    while(t <= test) solve_problem(t++);
 
    return 0;
} 

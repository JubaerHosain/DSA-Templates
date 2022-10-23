#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(a)   a.begin(), a.end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


/*****User defined function*****/

void solve_problem() {
    int n; cin >> n;

    int xr = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        xr ^= a;
    }

    if(xr == 0 || n%2 == 0)
        cout << "Alice" << endl;
    else 
        cout << "Bob" << endl; 
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed << showpoint;
    cout << setprecision(15);
    
    solve_problem();

    return 0;
} 



/*
    1. if xor all number of an array is zero then after removing any single number(any random number -> not necessary from the array)
     there is no chance to make zero again.
    2. if xor all number of an array is non-zero then there is at least one number(any random number -> not necessary from the array)
     such that it's removal will make zero.
*/


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
    
    ll xr = 0;
    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        xr ^= a;
    }
    
    if(xr == 0)
        cout << "BOB" << endl;
    else 
        cout << "ALICE" << endl;
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

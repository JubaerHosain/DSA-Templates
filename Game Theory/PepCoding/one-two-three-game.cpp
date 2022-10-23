/*
    Two players Alice and Bob are playing a game. 
    They have a pile with n coins in it. 
    They can pick either 1 or 2 coins in one turn. 
    Alice goes first and they take alternate turns. 
    The player who picks the last coin is the winner. 
    Can you find out the winner?
*/


#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(a)   a.begin(), a.end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*
    what if 1, 2, 3, 4....r (what if they are not continous..see grandy number...)
    if n%(r+1) == 0 bob
    else alice
*/


/*****User defined function*****/

void solve_problem() {
    ll n; cin >> n;
    
    if(n%3 == 0) 
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



/*
    Given an array of integers, two players Alice and Bob are playing a game where 
    Alice can remove any number of element from the array that are multiples of 3. 
    Similarly, Bob can remove any number of element that are multiples of 5. 
    The player who can't remove any element loses the game. 
    The task is to find the winner of the game if Alice starts first and both play optimally.
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
    int n;
    cin >> n;

    int c3 = 0, c5 = 0;
    int flag = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a%3 == 0 && a%5 == 0)
            flag = 1;
        else if(a%3 == 0)
            c3 += 1;
        else if(a%5 == 0)
            c5 += 1;
    }

    c3 += flag;

    if(c3 > c5) 
        cout << "ALICE" << endl;
    else 
        cout << "BOB" << endl;
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

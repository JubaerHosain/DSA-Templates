/*
    1. if sum(A) != sum(B) then Alice wins.
    2. if sum(A) == sum(B) then
        2.1 if sturctures are same then Bob wins.
        2.2 if sturctures are different then Alice wins.
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
    int n, m;
    cin >> n >> m;

    /*
        0 <= a[i] <= 1e8
        0 <= b[i] <= 1e8
    */

    vector<int> a, b;
    
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x != 0)
            a.push_back(x);
    }
       
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        if(x != 0)
            b.push_back(x);
    }
    
    // structures are not same
    if(a.size() != b.size()) {
        cout << "ALICE" << endl;
    } else {
        sort(all(a));
        sort(all(b));
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                cout << "ALICE" << endl;
                return;
            }
        }
        cout << "BOB" << endl;
    }
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

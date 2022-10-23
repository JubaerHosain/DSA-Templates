#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(a)   a.begin(), a.end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

/*
    Grundy number: The minimum number that second player will never play.
    grundy[n] = mex(grundy[n-pick[0]], grundy[n-pick[1]], ....., grundy[n-pick[r-1]]);
*/

/*****User defined function*****/

const int N = 1e3 + 5;
vector<int> grundy(N, -1);

int find_mex(unordered_set<int> &nums) {
    for(int i = 0; i <= nums.size(); i++) {
        if(!nums.count(i)) 
            return i;
    }
}

int find_grundy(int n, vector<int> picks) {
    if(n == 0) 
        return grundy[n] = 0;
    else if(grundy[n] != -1)
        return grundy[n];
    
    unordered_set<int> nums;
    for(int v: picks) {
        if(n-v >= 0)
            nums.insert(find_grundy(n-v, picks));
    }

    return find_mex(nums);
}

void solve_problem() {
    int n; 
    cin >> n;

    int l; 
    cin >> l;

    vector<int> picks(l);
    for(int i = 0; i < l; i++)
        cin >> picks[i];

    
    int gnd = find_grundy(n, picks);

    if(gnd == 0)
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



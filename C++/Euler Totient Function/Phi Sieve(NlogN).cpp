#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
const int N = 1e6+5;
vector<int> phi(N);

// theory behind the scene is...................
//  ϕ(n) = n * ((p1-1)/p1) * ((p2-1)/p2) * ((p3-1)/p3)....((pn-1)/pn)
void phi_sieve() {
    for(int i = 1; i < N; i++) 
        phi[i] = i;

    for(int i = 2; i < N; i++) {
        // if i is not a prime number then continue 
        if(phi[i] != i)
            continue; 
        for(int j = i; j < N; j += i) {
            phi[j] /= i;
            phi[j] *= (i-1);
        }
    }
}


void solve_problem() {
    int t;
    cin >> t;

    while(t--) {
        int n; cin >> n;
        cout << phi[n] << endl;
    }
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

    phi_sieve();
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

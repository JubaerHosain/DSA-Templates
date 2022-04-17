#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

// O(sqrt(N)) time complexity
int phi(int n) {
    int res = n;
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            res /= i;
            res *= (i-1);
            while(n%i == 0)
                n /= i;
        }
    }

    if(n > 1) {
        res /= n;
        res *= (n-1);
    }

    return res;
}

void solve_problem() {
    int N;
    cin >> N;

    int cnt = phi(N);

    cout << cnt << endl;
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

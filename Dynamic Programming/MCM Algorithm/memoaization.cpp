#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 1e3+5;
int a[N];
ll dp[N][N];
int split[N][N];

void print_parenthesis(int i, int j) {
    if(i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        print_parenthesis(i, split[i][j]);
        cout << "*";
        print_parenthesis(split[i][j]+1, j);
        cout << ")";
    }
}


ll lookup_chain(int i, int j) {
    if(dp[i][j] < 1e18)
        return dp[i][j];
    else if(i == j)
        return dp[i][j] = 0;
    
    for(int k = i; k < j; k++) {
        ll tmp = lookup_chain(i, k) + lookup_chain(k+1, j) + a[i-1] * a[k] * a[j];
        if(tmp < dp[i][j]) {
            dp[i][j] = tmp;
            split[i][j] = k;
        }
    }
    
    return dp[i][j];
}

void solve_problem() {
    int n;
    cin >> n;

    // there has n-1 matrix
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            dp[i][j] = 1e18;
    }

    // not from 0th index
    cout << "Min Cost: " << lookup_chain(1, n-1) << endl;

    cout << "Parenthesis: ";
    // not from 0 th index
    print_parenthesis(1, n-1);
    cout  << endl;
} 
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(5);
 
    int test = 1;
    cin >> test;
    while(test--) {
        solve_problem();
    }
 
    return 0;
} 
#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
void solve_problem() {
    int m, n;
    cin >> m >> n;

    // a is a polynomial of degree m-1
    // b is a polynomial of degree n-1
    vector<ll> a(m), b(n), c(m+n-1, 0);
    for(int i = 0; i < m; i++) 
        cin >> a[i];
    for(int i = 0; i < n; i++) 
        cin >> b[i];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            c[i+j] += a[i]*b[j];
    }

    // c is porduct of a and b which degree is m+n-2
    for(int i = 0; i < m+n-1; i++) 
        cout << c[i] << " ";
    cout << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(v)   v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

// if a is positive then it has exactly one minimum
// if a is negative then it has exactly one maximum

// draw the graph of that equation in desmos

#define eps 1e-7
#define f(x, b, c) ((x)*(x) + b*(x) + c)/sin(x)

void solve_problem() {
    double  l = 0, r = M_PI/2;

    double b, c;
    cin >> b >> c;

    while(r-l > eps) {
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        double f1 = f(m1, b, c);
        double f2 = f(m2, b, c);
        if(f1 < f2) 
            r = m2;
        else 
            l = m1;
    }

    cout << min(f(l, b, c), f(r, b, c)) << endl;
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
    cin >> test;
    while(test--) solve_problem();

    return 0;
} 


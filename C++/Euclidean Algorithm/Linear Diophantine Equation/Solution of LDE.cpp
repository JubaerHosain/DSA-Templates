#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
ll extended_euclidean(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x0, y0;
    ll g = extended_euclidean(b, a%b, x0, y0);
    x = y0;
    y = x0 - y0*(a/b);
    return g;
}

bool has_solution(ll a, ll b, ll c, ll &x, ll &y) {
    ll x0, y0;
    ll g = extended_euclidean(abs(a), abs(b), x0, y0);

    if(c%g != 0)
        return false;

    cout << g << endl;

    x = x0 * (c/g);
    y = y0 * (c/g);

    return true;
}


void solve_problem() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll x, y;
    if(has_solution(a, b, c, x, y))
        cout << x << " " << y << endl;
    else
        cout << "Integral solution dosen't exists" << endl;
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

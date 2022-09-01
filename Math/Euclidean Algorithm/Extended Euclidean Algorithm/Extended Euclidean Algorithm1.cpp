#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

pair<ll, pair<ll, ll>> extended_euclidean(ll a, ll b) {
    if(b == 0) {
        // {gcd, {x, y}}
        pair<ll, pair<ll, ll>> ans;
        ans.first = a;
        ans.second.first = 1;
        ans.second.second = 0;
        return ans;
    }

    pair<ll, pair<ll, ll>> after_ans = extended_euclidean(b, a%b);
    pair<ll, pair<ll, ll>> before_ans;
    before_ans.first = after_ans.first;
    before_ans.second.first = after_ans.second.second;
    before_ans.second.second = after_ans.second.first - (a/b)*after_ans.second.second;
    return before_ans;
}

void solve_problem() {
    ll a, b;
    cin >> a >> b;
    pair<ll, pair<ll, ll>> ans = extended_euclidean(a, b);
    cout << "gcd " << ans.first << endl; 
    cout << "x   " << ans.second.first << endl; 
    cout << "y   " << ans.second.second << endl; 
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
    // cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

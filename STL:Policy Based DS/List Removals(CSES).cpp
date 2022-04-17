#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef tree<int, null_type, less<int>,
rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*****User defined function*****/
const int N = 2e5+5;
int a[N];

void solve() {
    int n;
    cin >> n;

    ordered_set set;
    rep(i, 1, n) {
        cin >> a[i];
        set.insert(i);
    }

    rep(i, 1, n) {
        int p;
        cin >> p;
        --p;
        int inx = *set.find_by_order(p);
        set.erase(inx);
        cout << a[inx] << " ";
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
 
    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 

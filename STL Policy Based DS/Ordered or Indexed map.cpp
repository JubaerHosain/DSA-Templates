//best use
template<class T> using ordered_set = tree<T, null_type, 
less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//it would be declared as ordered_set<type> variable_name;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//this should write after using namespace std
//typedef tree<int, null_type, less<int>,
//rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

//for set use less<type> comparator
//for multiset use less_equal<type> instead of less
//for map, use map type, here map<int, int>
//tree<key of map, value of map, ..., ..., ....> ordered_map;
typedef tree<int, int, less<int>,
rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//less_equal for ordered_multiset
 
/*****User defined function*****/
const int N = 3e4+5;
vector<int> a(N);

void solve() {
    

    ordered_set map;
    map[1] = 3;
    map[3] = 8;
    map[1] = 9;

    print(map[1]);
    auto it = *map.find_by_order(1);
    print(it.first);
    print(it.second);
    auto it1 = map.find_by_order(0);
    print((*it1).first);
    print((*it1).second);
    
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

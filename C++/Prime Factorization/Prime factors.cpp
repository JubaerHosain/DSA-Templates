#include<bits/stdc++.h>
using namespace std;
#define all(v)                  v.begin(), v.end()
#define rall(v)                 v.rbegin(), v.rend()
#define des()                   greater<int>()
#define rep(i, a, n)            for(ll i = a; i < n; i++)  
#define rrep(i, n, a)           for(ll i = n; i >= a; i--)
#define pqueue                  priority_queue
#define umap                    unordered_map
#define uset                    unordered_set
#define pub                     push_back
#define pob                     pop_back  
#define endl                    '\n' //in interactive problem should not use this
#define println                 cout << endl
#define scan_array(arr, n)      for(ll i = 0; i < n; i++) { cin >> arr[i]; }
#define print_array(arr, n)     for(ll i = 0; i < n; i++) { cout << arr[i] << " "; } println;
#define print(var)              cout << var << endl;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
const int p = 1e9+7;
const int eps = 1e-9;
const int inf = INT_MAX;
const int N = 1e6+10;

/*************User defined function*************/
void solve() {
    int n;
    cin >> n;
    
    //sqrt(N) time complexity
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            int cnt = 0;
            while(n%i == 0) {
                cnt++;
                n /= i;
            }
            cout << i << "^" << cnt << endl;
        }
    }

    if(n > 1)
        cout << n << "^" << 1 << endl;
}


/*************main function*************/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    int test = 1;
    //cin >> test;
    while(test-- > 0) {
        solve();
    }

    return 0;
}    

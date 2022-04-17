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
typedef vector<vector<ll>> vii;
const int p = 1e9+7;
const int eps = 1e-9;
const int inf = INT_MAX;
const int N = 50+10;

/*************Binary exponentiation*************/
vii mul(vii a, vii b, int m) {
    vii res(m, vector<ll>(m, 0));

    rep(i, 0, m) {
        rep(j, 0, m) {
            rep(k, 0, m) {
                res[i][j] += (a[i][k]%p * b[k][j]%p)%p;
                res[i][j] = res[i][j]%p;
            }
        }
    }

    return res;
}

vii mul(vii v, int m, int n) {
    vii res(m, vector<ll>(m));              //identity matrix
    rep(i, 0, m) {
        rep(j, 0, m) {
            if(i == j) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }

    while(n) {
        if(n%2) {
            res = mul(res, v, m);
            n--;
        } else {
            v = mul(v, v, m);
            n /= 2;
        }
    }

    return  res;
}

/*************User defined function*************/
void solve() {
    int m, n;
    cin >> m >> n;

    vii v(m, vector<ll>(m));
    rep(i, 0, m) {
        rep(j, 0, m) {
            cin >> v[i][j];
        }
    }

    v = mul(v, m, n);

    rep(i, 0, m) {
        rep(j, 0, m) cout << v[i][j]%p << " ";
        println;
    }
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
    cin >> test;
    while(test-- > 0) {
        solve();
    }

    return 0;
}    

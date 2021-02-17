#include<bits/stdc++.h>
using namespace std;
#define all(v)                  v.begin(), v.end()
#define rall(v)                 v.rbegin(), v.rend()
#define des()                   greater<int>()
#define rep(i, a, n)            for(int i = a; i < n; i++)  
#define rrep(i, n, a)           for(int i = n; i >= a; i--)
#define pqueue                  priority_queue
#define umap                    unordered_map
#define uset                    unordered_set
#define pub                     push_back
#define pob                     pop_back  
#define endl                    '\n' //in interactive problem should not use this
#define println                 cout << endl
#define scan_array(arr, n)      for(int i = 0; i < n; i++) { cin >> arr[i]; }
#define print_array(arr, n)     for(int i = 0; i < n; i++) { cout << arr[i] << " "; } println;
#define print(var)              cout << var << endl
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
const int p = 1e9+7;
const int eps = 1e-9;
const int inf = INT_MAX;
const int N = 1e5+5;

/*************Range Sum Query*************/
vi tree(0), a(0);
int len;

void buildRSQ(int low, int high, int i) {
    if(low == high) {
        tree[i] = a[low];
        return;
    }

    int mid = low+(high-low)/2;
    buildRSQ(low, mid, 2*i+1);
    buildRSQ(mid+1, high, 2*i+2);
    tree[i] = tree[2*i+1]+tree[2*i+2];
}

int getSum(int i, int low, int high, int l, int r) {
    if(low >= l && high <= r) {                     //total overlap
        return tree[i];
    } else if(high < l || low > r) {                //no overlap
        return 0;
    }

    int mid = low+(high-low)/2;
    return getSum(2*i+1, low, mid, l, r) + getSum(2*i+2, mid+1, high, l, r);
}

int getSum(int l, int r) {
    return getSum(0, 0, len-1, l, r);
}

void update(int root, int low, int high, int i, int diff) {
    if(i < low || i > high) return;
    tree[root] += diff;
    if(low != high) {
        int mid = low+(high-low)/2;
        update(2*root+1, low, mid, i, diff);
        update(2*root+2, mid+1, high, i, diff);
    }
}

void update(int i, int val) {
    int diff = val-a[i];
    a[i] = val;
    update(0, 0, len-1, i, diff);
}

/*************User defined function*************/
void solve() {
    int n;
    cin >> n;

    //must have initialize
    a.resize(n);
    scan_array(a, n);
    len = n;
    tree.resize(4*n);
    buildRSQ(0, n-1, 0);

    cout << getSum(0, 3) << endl;
    update(3, 6);
    cout << getSum(0, 4) << endl;
    update(3, 1);
    cout << getSum(0, 4) << endl;
}

/*************main function*************/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    // int test;
    // cin >> test;
    // while(test-- > 0) {
    //     solve();
    // }

    solve();

    return 0;
}    

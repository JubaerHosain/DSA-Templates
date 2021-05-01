#include<bits/stdc++.h>
using namespace std;
#define all(v)                  v.begin(), v.end()
#define pqueue                  priority_queue
#define endl                    '\n'//in interactive problem should not use this
#define print(var)              cout << var << endl
#define out(a, b)               cout << a << " " << b << endl
#define rep(i, s, n)            for(int i = s; i < n; i++)
#define rrep(i, n, s)           for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<vector<int>> vii;
const ll inf = INT_MAX;
const int N = 5e3+5;
const int p = 1e9+7;

/*************User defined function*************/
int fen[N];

void update(int i, int val) {
    while(i < N) {
        fen[i] += val;
        i = i+(i&(-i));
    }
}

int get_sum(int i) {
    int sum = 0;
    while(i > 0) {
        sum += fen[i];
        i = i-(i&(-i));
    }

    return sum;
}

int range_sum(int l, int r) {
    return get_sum(r) - get_sum(l-1);
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n+1);
    rep(i, 0, n) cin >> v[i+1];

    rep(i, 1, n+1) update(i, v[i]);

    print(get_sum(4));
    print(range_sum(8, 10));
    update(2, 5);
    print(get_sum(4));
    print(range_sum(8, 10));
}

/*************main function*************/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    cout << fixed << showpoint;
    cout << setprecision(12);

    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}    

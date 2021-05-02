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
const int p = 1e9+7;
const int N = 1e6+5;

/*************User defined function*************/
ll fen[N];

void update(int i, int val) {
    while(i < N) {
        fen[i] += val;
        i = i+(i&(-i));
    }
}

void range_update(int l, int r, int val) {
    update(l, val);
    update(r+1, -val);
}

ll get_sum(int i) {
    ll sum = 0;
    while(i > 0) {
        sum += fen[i];
        i = i-(i&(-i));
    }

    return sum;
}

void solve() {
    int n, m, c;
    cin >> n >> m >> c;

    while(m--) {
        char ch;
        cin >> ch;
        
        if(ch == 'S') {
            int u, v, k;
            cin >> u >> v >> k;
            range_update(u, v, k);
        } else {
            int p;
            cin >> p;
            print(get_sum(p)+c);
        }
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

    cout << fixed << showpoint;
    cout << setprecision(12);

    int test = 1;
    //cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}    

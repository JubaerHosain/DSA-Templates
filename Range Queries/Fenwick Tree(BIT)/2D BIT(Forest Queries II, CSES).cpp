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
 
/*****User defined function*****/
const int N = 1e3+5;
char a[N][N];
int tree[N][N];
 
void update(int x, int y, int val, int n) {
    for(int i = x; i <= n; i += (i&(-i))) 
        for(int j = y; j <= n; j += (j&(-j)))
            tree[i][j] += val; 
}
 
int get_sum(int x, int y) {
    int sum = 0;
 
    for(int i = x; i > 0; i -= (i&(-i))) 
        for(int j = y; j > 0; j -= (j&(-j)))
            sum += tree[i][j]; 
    
    return sum;
}
 
int query(int x1, int y1, int x2, int y2) {
    int a = get_sum(x2, y2);
    int b = get_sum(x2, y1-1);
    int c = get_sum(x1-1, y2);
    int d = get_sum(x1-1, y1-1);
    return a - b - c + d;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    rep(i, 1, n) rep(j, 1, n) {
        cin >> a[i][j];
        if(a[i][j] == '*') update(i, j, 1, n);
    }
 
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, y;
            cin >> x >> y;
            if(a[x][y] == '.') {
                a[x][y] = '*';
                update(x, y, 1, n);
            } else {
                a[x][y] = '.';
                update(x, y, -1, n);
            }
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            print(query(x1, y1, x2, y2));
        }
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

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
const int N = 1e5+5;

bool cmp(pii a, pii b) {
    // sort by decending order of profit
    return a.second > b.second;
}

void solve() {
    int n;
    cin >> n;

    // {deadline, profit}
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        int d, p;
        cin >> d >> p;
        a[i] = {d, p};
    }

    sort(a.begin(), a.end(), cmp);

    // find max deadline
    int mx = 0;
    for(int i = 0; i < n; i++) 
        mx = max(mx, a[i].first);

    // do a work at dealline/latest time as possible
    
    vector<int> available(mx+1, -1);

    int profit = 0;
    for(int i = 0; i < n; i++) {
        for(int j = a[i].first; j >= 1; j--) {
            if(available[j] == -1) {
                profit += a[i].second;
                available[j] = 0;
                break;
            }
        }
    }
    
    cout << profit << endl;
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
    cout << setprecision(5);
 
    int test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 

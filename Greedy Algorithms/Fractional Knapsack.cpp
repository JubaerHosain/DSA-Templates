#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef pair<double, double> pdd;

/*****user defined function*****/

bool cmp(pdd a, pdd b) {
    //sort by larger profit per unit
    return a.second/a.first > b.second/b.first;
}

void solve_problem() {
    int n, w;
    cin >> n >> w;

    //{weight, profit}
    vector<pdd> pairs(n);
    for(int i = 0; i < n; i++) {
        cin >> pairs[i].first;
        cin >> pairs[i].second;
    }

    sort(pairs.begin(), pairs.end(), cmp);

    double ans = 0;
    for(int i = 0; i < n; i++) {
        if(w >= pairs[i].first) {
            ans += pairs[i].second;
            w -= pairs[i].first;
        }
        else {
            ans += w * pairs[i].second/pairs[i].first;
            break;
        }
    }

    cout << "Maximum profit " << ans << endl;
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
    while(test--) solve_problem();

    return 0;
} 

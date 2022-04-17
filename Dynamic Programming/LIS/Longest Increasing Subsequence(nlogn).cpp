#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 5e5+5;

void solve_problem() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    // nlogn approach using binary search

    vector<int> lis;
    lis.push_back(a[0]);
    for(int i = 1; i < n; i++) {
        if(lis.back() < a[i]) {
            lis.push_back(a[i]);
        } else {
            // lower bound works bcz it is possible to replace by itself
            // we are not finding the sequence, just finding its size
            int inx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[inx] = a[i];
        }
    }

    cout << "Max LIS Length: " << lis.size() << endl;
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
    //cin >> test;
    while(test--) {
        solve_problem();
    }
 
    return 0;
} 

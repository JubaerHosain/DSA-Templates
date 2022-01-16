#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/

bool cmp(pii a, pii b) {
    //sort in ascending order by ending time
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

void solve_problem() {
    int n;
    cin >> n;

    vector<pii> times;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        times.push_back({x, y});
    }

    sort(times.begin(), times.end(), cmp);

    int cnt = 1, end = times[0].second;
    for(int i = 1; i < n; i++) {
        if(end <= times[i].first) 
            cnt++, end = times[i].second;
    }

    cout << "Maximum number of task: " << cnt << endl;
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
    while(test--)  solve_problem();
 
    return 0;
} 

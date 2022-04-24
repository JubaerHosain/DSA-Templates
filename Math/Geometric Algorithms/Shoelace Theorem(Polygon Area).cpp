#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e5+5;

struct Point {
    long long x, y;
};

void solve_task() {
    int n;
    cin >> n;

    vector<Point> points;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    ll area = 0;
    for(int i = 0; i < n; i++) {
        area += (points[i].x * points[(i+1)%n].y) - (points[(i+1)%n].x * points[i].y);
    }

    cout << 0.5 * abs(area) << endl;
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
        solve_task();
    }

    return 0;
} 

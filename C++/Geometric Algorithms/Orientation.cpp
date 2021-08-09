#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
struct Point {
    long long x, y;
};

ll orientation(Point a, Point b, Point c) {
    //val = 0, collinear
    //val > 0, clockwise
    //val < 0, anti-clockwise
    return (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
}

void solve_task() {
    Point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    ll val = orientation(a, b, c);

    if(val < 0)    
        cout << "LEFT" << endl;
    else if(val > 0)
        cout << "RIGHT" << endl;
    else
        cout << "TOUCH" << endl;
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
    cin >> test;
    while(test--) {
        solve_task();
    }

    return 0;
} 

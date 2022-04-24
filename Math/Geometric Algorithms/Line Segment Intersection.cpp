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
    ll val = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
    return val = (val == 0) ? 0 : (val > 0) ? 1 : -1;
}

bool on_segment(Point a, Point c, Point b) {
    //point c lies on line ab or not
    return c.x <= max(a.x, b.x) && c.x >= min(a.x, b.x) &&
           c.y <= max(a.y, b.y) && c.y >= min(a.y, b.y);
}

bool intersected(Point a, Point b, Point c, Point d) {
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);

    if(o1 != o2 && o3 != o4)
        return true;
    if(o1 == 0 && on_segment(a, c, b))
        return true;
    if(o2 == 0 && on_segment(a, d, b))
        return true;
    if(o3 == 0 && on_segment(c, a, d))
        return true;
    if(o4 == 0 && on_segment(c, b, d))
        return true;

    return false;
}

void solve_task() {
    Point a, b, c, d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    if(intersected(a, b, c, d))
        cout << "YES" << endl;
    else    
        cout << "NO" << endl;
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

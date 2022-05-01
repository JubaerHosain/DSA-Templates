#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
struct point {
    ll x, y;
    
    bool equal(point p) {
        return x == p.x && y == p.y;
    }
};

//first point
point start;

ll orientation(point a, point b, point c) {
    //val = 0 collinear, val > 0 clockwise, val < 0 anti-clockwise
    return (b.y - a.y)*(c.x - b.x) - (c.y - b.y)*(b.x - a.x);
}

ll distance(point a, point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool cmp(point a, point b) {
    if(orientation(start, a, b) < 0) 
        return true;
    else if(orientation(start, a, b) > 0)
        return false;
    else
        return distance(start, a) < distance(start, b);
}

vector<point> outerTrees(vector<point> points) {
    //find leftmost
    int start_pos = 0;
    for(int i = 1; i < points.size(); i++) {
        if(points[i].x < points[start_pos].x) 
            start_pos = i;
        else if(points[i].x == points[start_pos].x && points[i].y < points[start_pos].y)
            start_pos = i;
    }
    
    swap(points[0], points[start_pos]);
    
    //first point;
    start = points[0];
    
    //sort according to angle with y axis
    sort(points.begin()+1, points.end(), cmp);

    //if collinear point in the end then reverse those
    //points for min distance point stays at far distance from start
    int i = points.size()-1;
    while(i >= 0 && orientation(start, points[i], points[points.size()-1]) == 0)
        i--;

    int left = i+1, right = points.size()-1;
    while(left < right) {
        point tmp = points[left];
        points[left] = points[right];
        points[right] = tmp;
        left++; right--;
    }
    
    stack<point> hull;
    hull.push(points[0]);
    hull.push(points[1]);
    for(int i = 2; i < points.size(); i++) {
        point temp = hull.top();
        hull.pop();
        
        while(hull.size() > 0 && orientation(points[i], temp, hull.top()) < 0) {
            temp = hull.top();
            hull.pop();
        }
        
        hull.push(temp);
        hull.push(points[i]);
    }
    
    points.resize(hull.size());
    for(int i = 0; i < points.size(); i++) {
        point temp = hull.top();
        hull.pop();
        points[i] = {temp.x, temp.y};
    }
    
    return points;
}

void solve_task() {
    int n;
    cin >> n;

    vector<point> points(n);
    for(int i = 0; i < n; i++) 
        cin >> points[i].x >> points[i].y;
    
    points = outerTrees(points);

    cout << points.size() << endl;
    for(point p: points) 
        cout << p.x << " " << p.y << endl;
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
    while(test--) solve_task();
    
 
    return 0;
} 


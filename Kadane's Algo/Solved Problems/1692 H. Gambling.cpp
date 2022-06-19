#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

typedef pair<int, pair<int, int>> p3;
 
/*****User defined function*****/

p3 get_tmp(int val, vector<int> &inx) {
    vector<pii> v;
    v.push_back({1, inx[0]});
    for(int i = 1; i < inx.size(); i++) {
        if(inx[i]-inx[i-1] > 1) 
            v.push_back({-(inx[i]-inx[i-1]-1), 0});
        v.push_back({1, inx[i]});
    }
    
    // kadens algo
    int n = v.size();
    int mx = v[0].first, curr = v[0].first;
    int l = v[0].second, r = v[0].second;

    int pos = v[0].second;
    for(int i = 1; i < n; i++) {
        if(v[i].first+curr > v[i].first) curr += v[i].first;
        else curr = v[i].first, pos = v[i].second;
        if(curr > mx) {
            mx = curr, l = pos, r = v[i].second; 
        }
    }

    return {mx, {l, r}};
}

void solve_problem() {
    int n;
    cin >> n;

    int a;
    unordered_map<int, vector<int>> inx;
    for(int i = 0; i < n; i++) {
        cin >> a;
        inx[a].push_back(i);
    }

    int val, l, r;
    int curr = 0;
    for(auto &it: inx) {
        p3 tmp = get_tmp(it.first, it.second);
        if(tmp.first > curr) {
            curr = tmp.first;
            val = it.first;
            l = tmp.second.first + 1;
            r = tmp.second.second + 1;
        }
    }

    cout << val << " " << l << " " << r << endl;
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(5);
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();
    
 
    return 0;
} 



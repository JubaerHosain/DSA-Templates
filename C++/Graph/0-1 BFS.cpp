problem link: https://www.codechef.com/problems/REVERSE

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
// change endl for interactiv problems


// In bfs, at the same time queue may contain at 
// most 2 level nodes. (x th, x+1 th) level. 0-1 bfs uses this observation

// 0-1 bfs need not visited array
// uses deque (to push front and back both if need)

const int N = 1e5 + 5;
const int inf = 1e9;
// {node, weight(0/1)} 
vector<pair<int, int>> g[N];
vector<int> level(N, inf);

int bfs01(int src, int dest) {
    deque<int> q;
    q.push_back(src);
    level[src] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        for(auto child: g[u]) {
            int v = child.first;
            int w = child.second;
            if(level[u] + w < level[v]) {
                // why visited array not used?? there is a case for 0-1 bfs.
                // each node can be pushed at max 2 times
                // bcz not used visited array (if used then exactly one time)
                level[v] = w + level[u];
                if(w == 1) {
                    q.push_back(v);
                }
                else {
                    // this v will be process in the same level as u
                    // bcz pushed in the front
                    q.push_front(v);
                }
            }
        }
    }

    return level[dest] == inf ? -1 : level[dest];
}


void solve_problem() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if(u == v) continue;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }

    cout << bfs01(1, n);
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

// O(m^n) 

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 1e5+5;
vector<int> graph[N];
vector<int> color(N, 0);

bool is_possible(int u, int c) {
    for(int v: graph[u]) {
        if(color[v] == c)
            return false;
    }
    return true;
}

// nc = number of color
bool color_graph(int u, int n, int nc) {
    // after completing n 
    if(u == n+1)
        return true;

    for(int c = 1; c <= nc; c++) {
        if(is_possible(u, c)) {
            color[u] = c;
            if(color_graph(u+1, n, nc))
                return true;
            // this is backtracking
            color[u] = 0;
        }
    }

    return false;
}

void solve_problem() {
    int n, m, nc;
    cin >> n >> m >> nc;

    // n = nodes 
    // m = edges 
    // nc = number of color 

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if(color_graph(1, n, nc)) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }

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
    // cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

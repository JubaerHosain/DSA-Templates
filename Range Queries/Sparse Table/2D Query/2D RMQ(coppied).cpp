#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vii;

const int N = 505, LG = 10;

int lg2[N];
int tree[N][N][LG][LG];

void build_tree(vii &grid, int n, int m) { 
    // 0 indexed, n = row, m = col
    for (int i = 2; i < N; i++)
        lg2[i] = lg2[i >> 1] + 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            tree[i][j][0][0] = grid[i][j];
        
    
    for (int a = 0; a < LG; a++) {
        for (int b = 0; b < LG; b++) {
            if (a + b == 0)
                continue;
            for (int i = 0; i + (1 << a) <= n; i++) {
                for (int j = 0; j + (1 << b) <= m; j++) {
                    if (!a)
                        tree[i][j][a][b] = max(tree[i][j][a][b - 1], tree[i][j + (1 << (b - 1))][a][b - 1]);
                    else
                        tree[i][j][a][b] = max(tree[i][j][a - 1][b], tree[i + (1 << (a - 1))][j][a - 1][b]);
                }
            }
        }
    }
}

int get_max(int x1, int y1, int x2, int y2) {
    x2++;
    y2++;
    int a = lg2[x2 - x1], b = lg2[y2 - y1];
    return max(
        max(tree[x1][y1][a][b], tree[x2 - (1 << a)][y1][a][b]),
        max(tree[x1][y2 - (1 << b)][a][b], tree[x2 - (1 << a)][y2 - (1 << b)][a][b]));
}

void solve_problem() {
    int n, m; 
    cin >> n >> m;

    vii grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    // 0 indexed
    build_tree(grid, n, m);

    int q;
    cin >> q;
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "max: " << get_max(x1, y1, x2, y2) << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
}


// https://www.youtube.com/watch?v=4BBB0mvvbGA&ab_channel=ApnaCollege


#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

bool is_safe(int x, int y, int n, int** grid) {
    if(x < n && y < n && grid[x][y] == 1)
        return true;
    return false;
}

// not all possible path..only one path..
// try yourself to find all possible path..
// change little bit logic like n queen problem
bool move_rat(int x, int y, int n, int** grid, int** res) {
    if(x == n-1 && y == n-1) 
        return true;

    // move down 
    if(is_safe(x, y, n, grid)) {
        res[x][y] = 1;
        // move down 
        if(move_rat(x+1, y, n, grid, res)) 
            return true;
        // move right 
        if(move_rat(x, y+1, n, grid, res)) 
            return true;
        // this backtracking
        res[x][y] = 0;
    }
    
    return false;
}

void solve_problem() {
    int n;
    cin >> n;

    // grid[i][j] == 0, obstracle
    // otherwise can move 
    // this problem only moves right and down..
    // find solutin which will moves 4 direction

    int** grid = new int*[n];
    int** res = new int*[n];
    for(int i = 0; i < n; i++) {
        res[i] = new int[n];
        grid[i] = new int[n];
    }
        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            res[i][j] = 0;
        }
    }

    if(move_rat(0, 0, n, grid, res)) {
        cout << "One possible path:" << endl;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }
    else {
        cout << "No path exists.";
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

#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int inf = 1e9+5;
int mod = 1e9+7;
const int N = 1e3+5;
int n, m;
char g[N][N];
int level[N][N];
bool used[N][N];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; //{D, U, R, L}

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool is_corner(pii &u) {
    return (u.first == 0 || u.second == 0 || u.first == n-1 || u.second == m-1);
}

void bfs1(vector<pii> &monstars) {
    queue<pii> q;
    for(pii src: monstars) {
        q.push({src.first, src.second});
        level[src.first][src.second] = 0;
        used[src.first][src.second] = true;
    }

    while(!q.empty()) {
        pii u = q.front();
        q.pop();

        rep(i, 0, 3) {
            int x = u.first + dir[i][0];
            int y = u.second + dir[i][1];
            if(valid(x, y) && !used[x][y] && g[x][y] != '#') {
                q.push({x, y});
                used[x][y] = true;
                level[x][y] = 1 + level[u.first][u.second];
            }
        }
    }
} 

void bfs2(pii &src) {
    queue<pair<pii, int>> q;   //{{x, y}, level}
    q.push({src, 0});
    used[src.first][src.second] = true;

    pii dst;
    bool escaped = false;
    map<pii, pair<pii, char>> parent;
    while(!q.empty()) {
        pii u = q.front().first;
        int d = q.front().second;
        q.pop();

        rep(i, 0, 3) {
            int x = u.first + dir[i][0];
            int y = u.second + dir[i][1];
            if(valid(x, y) && !used[x][y] && g[x][y] != '#' && d+1 < level[x][y]) {
                char ch;
                if(i == 0) ch = 'D';
                else if(i == 1) ch = 'U';
                else if(i == 2) ch = 'R';
                else ch = 'L';

                used[x][y] = true;
                q.push({{x, y}, d+1});
                parent[{x, y}] = {u, ch};

                dst = {x, y};
                if(is_corner(dst)) {
                    escaped = true;
                    break;
                }
            }
        }

        if(escaped) break;
    }

    if(!escaped) {
        print("NO");
        return;
    }

    string ans;
    for(pii v = dst; v != src; v = parent[v].first) 
        ans.push_back(parent[v].second);
    
    reverse(ans.rbegin(), ans.rend());

    print("YES");
    print(ans.size());
    print(ans);
}

void solve() {
    cin >> n >> m;

    pii src;
    vector<pii> monstars;
    rep(i, 0, n-1) rep(j, 0, m-1) {
        cin >> g[i][j];

        level[i][j] = inf;
        if(g[i][j] == 'A')
            src = {i, j};
        else if(g[i][j] == 'M')
            monstars.push_back({i, j});
    }

    if(is_corner(src)) {
        print("YES");
        print(0);
        return;
    }
        
    bfs1(monstars);

    rep(i, 0, n-1) rep(j, 0, m-1) used[i][j] = false;

    bfs2(src);
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
        solve();
    }
 
    return 0;
} 

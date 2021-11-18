#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 1e3+5;
vector<bool> blocked;
vector<int> sub_size;
vector<vector<int>> tree;

int query(int y) {
    int node;
    cout << '? ' << y;
    fflush(stdout);
    cin >> node;
    return node;
}

void print(int x) {
    cout << '! ' << x << endl;
    fflush(stdout);
}

void update_subtree_size(int u, int p) {
    if(blocked[u]) {
        sub_size[u] = 0;
        return;
    }

    sub_size[u] = 1;
    for(int v: tree[u]) {
        if(v == p)
            continue;
        update_subtree_size(v, u);
        sub_size[u] += sub_size[v];
    }
}

int find_centroid(int u, int p, int n) {
    for(int v: tree[u]) {
        if(v == p || blocked[v])
            continue;
        if(sub_size[v] > n/2)
            return find_centroid(v, u, n);
    }
    return u;
}

void recurr(int u, int n) {
    update_subtree_size(u, -1);
    int centroid = find_centroid(u, -1, sub_size[u]);
    int y = query(centroid);
    if(y == -1) {
        print(centroid);
        return;
    }
    blocked[centroid] = true;
    recurr(y, n);
}

void solve_problem() {
    int n;
    cin >> n;

    tree.clear();
    tree.resize(n+1);
    blocked.resize(n+1, false);
    sub_size.resize(n+1, 0);

    for(int i = 1; i <= n-1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    recurr(1, n);
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
    while(test--) solve_problem();
 
    return 0;
} 

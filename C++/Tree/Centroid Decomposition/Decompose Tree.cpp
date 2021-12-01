#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****Centroid Decomposition*****/
const int N = 2e5+5;
set<int> tree[N];
vector<int> parent(N);
vector<int> subtree_size(N);

int find_subtree(int u, int p) {
    subtree_size[u] = 1;
    for(int v: tree[u]) {
        if(v == p) continue;
        subtree_size[u] += find_subtree(v, u);
    }
    return subtree_size[u];
}

int find_centroid(int u, int p, int n) {
    for(int v: tree[u]) {
        if(v != p && subtree_size[v] > n/2)
            return find_centroid(v, u, n);
    }
    return u;
}

void decompose_tree(int u, int p) {
    int size = find_subtree(u, p);
    int centroid = find_centroid(u, p, size);
    parent[centroid] = p;
    for(int v: tree[centroid]) {
        tree[v].erase(centroid);
        decompose_tree(v, centroid);
    } 
}

/*****User defined function*****/
void solve_problem() {
    int n;
    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].insert(v);
        tree[v].insert(u);
    }

    decompose_tree(1, 0);
    
    for(int i = 1; i <= n; i++)
        cout << i << " " << parent[i] << endl;
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

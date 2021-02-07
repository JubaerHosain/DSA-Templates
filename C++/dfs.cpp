const int N = 2e5+5;
vector<int> g[N];
bool visited[N];

void dfs(int u, vector<int> &comp) {
    visited[u] = true;
    comp.add(u);

    for(auto v: g[u]) {
        if(!visited[v]) {
            dfs(v, comp);
        }
    }
}

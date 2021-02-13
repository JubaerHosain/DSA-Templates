bool used[N];
vector<int> g[N];

void dfs(int u) {
    used[u] = true;
    for(int v: g[u]) {
        if(!used[v]) dfs(v);
    }
}

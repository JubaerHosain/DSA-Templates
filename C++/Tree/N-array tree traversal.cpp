void dfs(int u, int p) {         //dfs(child, parent)
    for(auto v: g[u]) {
        if(v != p) {             //should not go to parent from child
            dfs(v, u);
        }
    }
}

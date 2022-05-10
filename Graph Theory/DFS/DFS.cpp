void dfs(int u, int cnt) {
    used[u] = 1;
    cc_no[u] = cnt;
    
    for(int v: g[u]) {
        if(!used[v]) 
            dfs(v, cnt);
    }
}

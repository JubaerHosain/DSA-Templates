bool bfs(int src, int dest, int n) {
    fill(used, used+n+1, false);

    queue<int> q;
    q.push(src);
    used[src] = true;
    dist[src] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        rep(v, 1, n) {
            if(!used[v] && graph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                dist[v] = 1 + dist[u];
                used[v] = true;

                if(v == dest)
                    return true;
            }
        }
    }

    return false;
}

/*************Dijkstra Algo*************/
vector<pii> g[N];
vector<int> prnt(N);
vector<ll> d(N, inf);
vector<bool> used(N);

void dijkstra(int u) {
    priority_queue<pii, vector<pii>, greater<pii>> q;  //{w, v}
    q.push({0, u});
    d[u] = 0;

    while(!q.empty()) {
        u = q.top().second;
        q.pop();

        if(used[u]) continue;
        used[u] = true;

        for(auto a: g[u]) {
            ll v = a.first, w = a.second;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.push({d[v], v});
                prnt[v] = u;
            }
        }
    }
}

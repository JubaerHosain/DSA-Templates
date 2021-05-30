/*************Dijkstra Algo*************/
vector<pll> g[N];                               //{v, w}
ll dist[N];
bool used[N];

void dijkstra(int u) {
    pqueue<pll, vector<pll>, greater<pll>> pq;  //{w, v}
    pq.push({0, u});
    dist[u] = 0;

    while(!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        if(used[u]) continue;
        used[u] = true;

        for(auto a: g[u]) {
            ll v = a.first, w = a.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

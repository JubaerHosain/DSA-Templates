vector<int> prnt, rnk;

rnk = vector<int>(n, 1);
prnt = vector<int>(n, -1);

int find(int u) {
    if(prnt[u] == -1) return u;
    return prnt[u] = find(prnt[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if(rnk[u] < rnk[v]) swap(u, v);

    rnk[u] += rnk[v];
    prnt[v] = u;
}


  

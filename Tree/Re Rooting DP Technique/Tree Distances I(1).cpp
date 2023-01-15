#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
int mx1[N], mx2[N], child[N];
// child = child of u through which it has max height

// calculate mx1 and mx2 for each node
void dfs1(int u, int p = -1) {
	mx1[u] = 0;
	mx2[u] = 0;
	for (auto v : g[u]) {
		if (v == p)continue;
		dfs1(v, u);

        if(mx1[u] < 1 + mx1[v]) {
            mx2[u] = mx1[u];
            mx1[u] = 1 + mx1[v];
            child[u] = v;
        }
		else if (mx2[u] < 1 + mx1[v]) {
			mx2[u] = 1 + mx1[v];
		}
	}
}

// calculate for every node x the maximum length of a path through its parent p
void dfs2(int u, int p = -1) {
	for (auto v : g[u]) {
		if (v == p) continue;
		if (child[u] == v) {
			if (mx1[v] < 1 + mx2[u]) {
				mx2[v] = mx1[v];
				mx1[v] = 1 + mx2[u];
				child[v] = u;
			}
			else {
				mx2[v] = max(mx2[v], 1 + mx2[u]);
			}
		}
		else {
			mx2[v] = mx1[v];
			mx1[v] = 1 + mx1[u];
			child[v] = u;
		}
		dfs2(v, u);
	}
}

int main() {
	int n, u, v;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1, -1);
	dfs2(1, -1);

	for (int i = 1; i <= n; i++) {
		cout << mx1[i] << " ";
	}
	return 0;
}

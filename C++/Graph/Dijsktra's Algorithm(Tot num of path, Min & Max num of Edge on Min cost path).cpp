
// what is the minimum price(cost) of such a route?
// how many minimum-price routes(path) are there? (modulo 109+7)
// what is the minimum number of flights(edges) in a minimum-price route?
// what is the maximum number of flights(edges) in a minimum-price route?

#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> vii;

/*****User defined function*****/
ll inf = 1e18+5;
int mod = 1e9+7;
const int N = 1e5+5;
vector<pii> g[N];
ll flight_cnt[N], cost[N];
int min_flight[N], max_flight[N];

void solve() {
    int n, m;
    cin >> n >> m;
    
    rep(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
    
    fill(cost, cost+N, inf);

    priority_queue<pii> pq;
    pq.push({0, 1});
    cost[1] = 0;
    flight_cnt[1] = 1;
    while(!pq.empty()) {
        ll d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        //same as visited array
        if(cost[u] < d)
            continue;

        for(pii it: g[u]) {
            int v = it.first;
            int c = it.second;
            if(cost[u] + c < cost[v]) {
                cost[v] = cost[u] + c;
                flight_cnt[v] = flight_cnt[u];
                min_flight[v] = min_flight[u] + 1;
                max_flight[v] = max_flight[u] + 1;
                pq.push({-cost[v], v});
            } else if(cost[u] + c == cost[v]) {
                flight_cnt[v] += flight_cnt[u];
                flight_cnt[v] %= mod;
                min_flight[v] = min(min_flight[v], min_flight[u] + 1);
                max_flight[v] = max(max_flight[v], max_flight[u] + 1);
            }
        }
    }

    cout << cost[n] << " ";
    cout << flight_cnt[n] << " ";
    cout << min_flight[n] << " ";
    cout << max_flight[n] << " ";
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
    //cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 9999+5;
int inf = 1e9, mod = 1e9+7;
int dist[N], used[N];
vector<int> g[N], primes;

bool is_prime(int n) {
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) return false;
    }

    return true;
}

bool is_valid(int a, int b) {
    int cnt = 0;

    while(a) {
        if(a%10 != b%10) 
            cnt++;
        a /= 10, b /= 10;
    }

    if(cnt == 1)    
        return true;
    else    
        return false;
}

void init() {
    rep(i, 1000, N-1) {
        if(is_prime(i)) 
            primes.push_back(i);
    }

    rep(i, 0, primes.size()-1) {
        rep(j, i+1, primes.size()-1) {
            if(is_valid(primes[i], primes[j])) {
                int u = primes[i], v = primes[j];
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    }
}

void do_bfs(int a) {
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    used[a] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: g[u]) {
            if(!used[v]) {
                q.push(v);
                used[v] = 1;
                dist[v] = 1 + dist[u];
            }
        }
    }
}

void solve() {
    int a, b;
    cin >> a >> b;

    memset(used, 0, sizeof(used));
    memset(dist, -1, sizeof(dist));
    do_bfs(a);

    if(dist[b] == -1)
        print("Impossible");
    else
        print(dist[b]);
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

    init();
 
    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
 
    return 0;
}   

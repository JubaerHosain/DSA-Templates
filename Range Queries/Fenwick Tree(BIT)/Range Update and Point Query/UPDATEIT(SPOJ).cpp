#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*****User defined function*****/
// vector<ll> BIT(100005);
vector<ll> BIT;

void point_update(int i, int x, int n) {
    while(i <= n) {
        BIT[i] += x;
        i = i + (i & (-i));
    }
}

void range_update(int l, int r, int val, int n) {
    point_update(l, val, n);
    point_update(r+1, -val, n);
}

ll prefix_sum(int i) {
    ll sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i = i - (i & (-i));
    }
    return sum;
}

ll point_query(int i) {
    return prefix_sum(i);
}

void solve_problem() {
    int n, u;
    cin >> n >> u;

    // for(int i = 0; i < 100005; i++) 
    // BIT[i] = 0;

    // BIT.resize(n+5, 0); is not working 
    // Ekhabe Resize korle just size ta change hy, r jodi vector r 
    // length bare tahole oi koyekta elements e 0 assign hy, pura 
    // vector e na
    
    BIT.resize(n+5);
    for(ll &i: BIT) i = 0;
    	
    // 1 based indexing
    for(int i = 0; i < u; i++) {
        int l, r, val;
        cin >> l >> r >> val;
        range_update(l+1, r+1, val, n);
    }

    int q;
    cin >> q;
    while(q--) {
        int i;
        cin >> i;
        cout << point_query(i+1) << '\n';
    }
}
 
/*****main function*****/
int main() {
    
    int test = 1;
    cin >> test;
    while(test--) 
    	solve_problem();
    
    return 0;
} 

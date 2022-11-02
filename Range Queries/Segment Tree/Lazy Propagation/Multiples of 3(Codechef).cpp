#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


void solve(ll);

int main() {
    ll T = 1ll;
    // cin >> T;
    for(int i = 1; i <= T; i++) {
        solve(i);
    }
}
struct Node {
    int one, two, zero, lazy;
    Node() : one(0), two(0), zero(0), lazy(0) {}
    Node(int _one, int _two, int _zero) : one(_one), two(_two), zero(_zero) {
    }
};

const int N = 100000;
Node segtree[4*N];
int n,q;

void rotate(int node) {
    int z = segtree[node].zero;
    segtree[node].zero = segtree[node].two;
    segtree[node].two = segtree[node].one;
    segtree[node].one = z;
}
void build(int node,int start,int end){
    if(start==end){
        segtree[node].zero++;
        return;
    }
    int mid = start + (end - start) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    segtree[node].zero = segtree[2*node].zero + segtree[2*node+1].zero;
}
void propagate(int node, int start, int end) {
    for(int i=0;i<segtree[node].lazy;i++){
        rotate(node);
    }
    if (start != end) {
        segtree[2 * node].lazy += segtree[node].lazy;
        segtree[2 * node].lazy %= 3;
        segtree[2 * node + 1].lazy += segtree[node].lazy;
        segtree[2 * node + 1].lazy %= 3;
    }
    segtree[node].lazy = 0;
}

void update(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    if (end < left || start > right)
        return;
    if (left <= start && right >= end) {
        segtree[node].lazy++;
        propagate(node, start, end);
        return;
    }
    int mid = start + (end - start) / 2;
    update(2 * node, start, mid, left, right);
    update(2 * node + 1, mid + 1, end, left, right);
    segtree[node].zero = segtree[2*node].zero + segtree[2*node+1].zero;
    segtree[node].one = segtree[2*node].one + segtree[2*node+1].one;
    segtree[node].two = segtree[2*node].two + segtree[2*node+1].two;
    
}
int query(int node, int start, int end, int left, int right) {
    propagate(node, start, end);
    if (end < left || start > right)
        return 0;
    if (left <= start && right >= end) {
        return segtree[node].zero;
    }
    int mid = start + (end - start) / 2;
    return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
}
void update(int left, int right) {
    update(1, 0, n - 1, left, right);
}
int query(int left, int right) {
    return query(1, 0, n - 1, left, right);
}

void solve(ll TC) {
    cin >> n >> q;
    build(1,0,n-1);
    while (q--) {
        int t;
        cin >> t;
        int l, r;
        cin >> l >> r;
        if (t == 0) {
            update(l, r);
        } else {
            cout << query(l, r) << endl;
        }
    }
}

/*
 itne me hi thakk gaye?

 read question
 rethink your approach
 dont put --> n <-- in every for loop
 consider case = 0

 Expert before 2023
*/
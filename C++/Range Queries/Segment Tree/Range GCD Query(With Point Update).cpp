const int N = 1e5+5;
vector<int> a(N);
vector<int> tree(4*N);

int buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = a[l];

    int mid = (l + r) / 2;
    return tree[i] = __gcd(buildST(2*i+1, l, mid), buildST(2*i+2, mid+1, r));
}

int get_gcd(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)              //total overlap
        return tree[i];
    else if(sr < l || sl > r)           //partial overlap
        return 0;

    int mid = (sl + sr) / 2;
    return __gcd(get_gcd(2*i+1, sl, mid, l, r), get_gcd(2*i+2, mid+1, sr, l, r));
}

void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {                                  //update in the leaf node of the tree
        tree[i] = val;
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else 
        update(2*i+2, mid+1, sr, pos, val);
    
    tree[i] = __gcd(tree[2*i+1], tree[2*i+2]);      //update intermediate nodes after returning the value of the leaf node
}

int get_gcd(int l, int r, int n) {
    return get_gcd(0, 0, n-1, l, r);
}

void update(int pos, int val, int n) {
    a[pos] = val;
    update(0, 0, n-1, pos, val);
}

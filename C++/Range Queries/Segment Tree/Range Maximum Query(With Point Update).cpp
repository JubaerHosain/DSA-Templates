vector<int> a(N);
vector<int> tree(4*N);

int buildST(int i, int l, int r) {
    if(l == r) 
        return tree[i] = a[l];
    
    int mid = (l + r) / 2;
    return tree[i] = max(buildST(2*i+1, l, mid), buildST(2*i+2, mid+1, r));
}

int get_max(int i, int sl, int sr, int l, int r) {
    if(sl >= l && sr <= r)          // total overlap
        return tree[i];
    else if(sr < l || r < sl)       // no overlap;
        return INT_MIN;

    int mid = (sl + sr) / 2;
    return max(get_max(2*i+1, sl, mid, l, r), get_max(2*i+2, mid+1, sr, l, r));
}

void update(int i, int sl, int sr, int pos, int val) {
    if(sl == sr) {                           //update in the leaf node of the tree
        tree[i] = val;
        return;
    }
    
    int mid = (sl + sr) / 2;
    if(pos <= mid) 
        update(2*i+1, sl, mid, pos, val);
    else 
        update(2*i+2, mid+1, sr, pos, val);
    
    tree[i] = max(tree[2*i+1], tree[2*i+2]);  //update intermediate nodes after returning the value of the leaf node
}

int get_max(int l, int r, int n) {
    return get_max(0, 0, n-1, l, r);
}

void update(int pos, int val, int n) {
    a[pos] = val;
    update(0, 0, n-1, pos, val);
}

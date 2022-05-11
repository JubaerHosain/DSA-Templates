vector<int> v;

int kadens_algo(int n) {
    int mx = v[0];
    int curr = v[0];

    rep(i, 1, n) {
        curr = max(v[i], v[i]+curr);
        mx = max(mx, curr);
    }

    return mx;
} 

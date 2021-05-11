vector<int> v;

int kadens_algo(int n) {
    int mx = 0;
    int curr = 0;

    rep(i, 0, n) {
        curr = max(v[i], v[i]+curr);
        mx = max(mx, curr);
    }

    return mx;
}

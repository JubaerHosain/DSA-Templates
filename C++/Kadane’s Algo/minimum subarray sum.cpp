vector<int> v;

int kadens_algo(int n) {
    int mn = v[0];
    int curr = v[0];

    rep(i, 0, n) {
        curr = min(v[i], v[i]+curr);
        mn = min(mn, curr);
    }

    return mn;
}

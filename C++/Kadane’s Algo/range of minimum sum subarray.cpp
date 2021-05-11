vector<ll> v;

pii kadens_algo(int n) {
    int mn = v[0], curr = v[0];
    int l = 0, r = 0;

    int pos = 0;
    rep(i, 0, n) {
        if(v[i]+curr < v[i]) curr += v[i];
        else curr = v[i], pos = i;
        if(curr < mn) mn = curr, l = pos, r = i;
    }

    return {l, r};
}

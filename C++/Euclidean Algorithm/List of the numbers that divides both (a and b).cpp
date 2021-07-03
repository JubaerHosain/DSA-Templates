//1. find the gcd of a and b.
//2. All divisor of gcd is also divisor of both a and b.

void solve() {
    int a, b;
    cin >> a >> b;

    int gcd = __gcd(a, b);

    vector<int> div;
    int sq = sqrt(gcd);
    rep(i, 1, sq+1) {
        if(gcd%i == 0) {
            div.push_back(i);
            if(i*i != gcd)
                div.push_back(gcd/i);
        }
    }
  
    for(int i: div) cout << i << " ";
}

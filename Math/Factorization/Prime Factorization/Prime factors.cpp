/*************User defined function*************/
void solve() {
    int n;
    cin >> n;
    
    // sqrt(N) time complexity
    for(int i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            int cnt = 0;
            while(n%i == 0) {
                cnt++;
                n /= i;
            }
            cout << i << "^" << cnt << endl;
        }
    }

    if(n > 1)
        cout << n << "^" << 1 << endl;
}

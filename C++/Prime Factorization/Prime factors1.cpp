/*************Prime factors of n*************/
void primeFactors(int n) {
    vector<int> fts;
    for(int i = 2; i*i <= n; i++) {
        int cnt = 0;
        while(n%i == 0) {
            cnt++;
            n /= i;
        }
        if(cnt > 0) fts.add(i);
    }
}

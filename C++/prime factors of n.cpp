/*************Prime factors of n*************/
void primeFactors(ull n) {
    vector<ull> fts;
    for(ull i = 2; i <= sqrt(n); i++) {
        int cnt = 0;
        while(n%i == 0 and n > 0) {
            cnt++;
            n /= i;
        }
        if(cnt > 0) fts.add(i);
    }
}

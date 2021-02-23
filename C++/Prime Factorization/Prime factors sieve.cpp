/*************Sieve of prime factorization*************/
vector<int> factor(N, -1);

void factor_sieve() {
    for(int i = 4; i <= N; i += 2) {
        if(factor[i] == -1) factor[i] = 2;
    }

    for(int i = 3; i*i <= N; i += 2) {
        for(int j = 2*i; j <= N; j += i) {
            if(factor[j] == -1) factor[j] = i;
        }
    }
}

/*************User defined function*************/
void solve() {
    int n;
    cin >> n;

    int i = n;
    while(factor[i] != -1) {
        print(factor[i]);
        i = i / factor[i];
    }
    print(i);

    println;
}

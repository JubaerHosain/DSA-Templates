/*************Sieve of prime factorization*************/
const int N = 1e7+5;
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


    // find (prime factor, count) pair
    // count for each prime factor
    map<int, ll> mp; 
    int k = n;
    while(factor[k] != -1) {
        int num = factor[k];
        int cnt = 0;
        while(k%num == 0) {
            k /= num;
            cnt += 1;
        }
        mp[num] = cnt;
    }
    if(k > 1) mp[k] = 1;
    
}

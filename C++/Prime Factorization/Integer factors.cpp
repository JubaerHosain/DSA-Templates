    vector<int> fact;
    for(int i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            fact.push_back(i);
            fact.push_back(n/i);
        }
    }

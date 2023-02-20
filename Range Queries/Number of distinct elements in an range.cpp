// n^2 solution


vector<vector<int>> distinct(n, vector<int>(n, 0));
for(int i = 0; i < n; i++) {
    vector<int> mp(n, 0);
    int unique = 0;
    for(int j = i; j < n; j++) {
        int num = nums[j];
        if(!mp[num]) 
            unique += 1;

        mp[num] = 1;
        distinct[i][j] = unique;
    }
}

/*************Sparse Table of RMQ*************/
const int N = 1e5+5;
int table[N][30];

void build_table(vector<int> a, int n) {
    rep(i, 0, n) 
        table[i][0] = i;

    for(int j = 1; (1 << j) <= n; j++) {
        for(int i = 0; (i + (1 << j) - 1) < n; i++) {
            if(a[table[i][j-1]] < a[table[i+(1<<(j-1))][j-1]]) 
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i+(1<<(j-1))][j-1];
        }
    }
}

int get_min(int l, int r, vector<int> a) {
    int j = log2(r-l+1);
    if(a[table[l][j]] < a[table[r-(1<<j)+1][j]]) 
        return table[l][j];
    else
        return table[r-(1<<j)+1][j];
}

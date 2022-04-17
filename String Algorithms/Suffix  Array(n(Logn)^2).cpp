#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
struct suffix {
    int index;
    int rank, next_rank;
};

bool cmp(const suffix a, const suffix b) {
    if(a.rank == b.rank)
        return a.next_rank < b.next_rank;
    else
        return a.rank < b.rank;
}

void solve_problem() {
    string text, pattern;
    cin >> text;

    int n = text.size();
    vector<suffix> suffixes(n);
    for(int i = 0; i < n; i++) {
        suffixes[i].index = i; 
        suffixes[i].rank = text[i] - 'a';
        suffixes[i].next_rank = (i+1 < n) ? text[i+1] - 'a' : -1;
    }

    sort(suffixes.begin(), suffixes.end(), cmp);

    vector<int> index_of(n);
    for(int k = 4; k < 2*n; k <<= 1) {
        int rank = 0;
        int prev_rank = suffixes[0].rank;
        suffixes[0].rank = rank;
        index_of[suffixes[0].index] = 0;

        for(int i = 1; i < n; i++) {
            if(suffixes[i].rank == prev_rank &&
            suffixes[i].next_rank == suffixes[i-1].next_rank) {
                prev_rank = suffixes[i].rank;
                suffixes[i].rank = rank;
            }
            else {
                prev_rank = suffixes[i].rank;
                suffixes[i].rank = ++rank;
            }

            index_of[suffixes[i].index] = i;
        }

        for(int i = 0; i < n; i++) {
            int next_index = suffixes[i].index + k/2;
            suffixes[i].next_rank = (next_index < n) ? suffixes[index_of[next_index]].rank : -1;
        }

        sort(suffixes.begin(), suffixes.end(), cmp);
    }

    for(int i = 0; i < n; i++) {
        cout << suffixes[i].index << " ";
        // cout << suffixes[i].rank << " ";
        // cout << suffixes[i].next_rank << endl;
    }    
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    int test = 1;
    //cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
struct suffix {
    int index;
    int rank[2];
};

bool cmp(suffix a, suffix b) {
    if(a.rank[0] == b.rank[0]) 
        return a.rank[1] < b.rank[1];
    else
        return a.rank[0] < b.rank[0]; 
}

void radix_sort(vector<suffix> &suffixes, int inx) {
    if(inx < 0) return;

    int n = suffixes.size();
    //256 size not working
    //bcz rank may have upto n(see line 68-80)
    vector<int> count(max(258, n+1), 0);

    //added 1, bcz rank[inx] may have -1
    for(int i = 0; i < n; i++) 
        ++count[suffixes[i].rank[inx] + 1];

    for(int i = 1; i < count.size(); i++) 
        count[i] += count[i-1];
    
    vector<suffix> temp(n);
    for(int i = n-1; i >= 0; i--) {
        temp[count[suffixes[i].rank[inx] + 1] - 1] = suffixes[i];
        --count[suffixes[i].rank[inx] + 1];
    }

    for(int i = 0; i < n; i++)
        suffixes[i] = temp[i];

    radix_sort(suffixes, inx - 1);
}

vector<int> build_suffix_array(string &text) {
    int n = text.size();
    vector<suffix> suffixes(n);

    for(int i = 0; i < n; i++) {
        suffixes[i].index = i; 
        suffixes[i].rank[0] = text[i];
        suffixes[i].rank[1] = (i+1 < n) ? text[i+1] : -1;
    }

    radix_sort(suffixes, 1);
    //sort(suffixes.begin(), suffixes.end(), cmp);

    vector<int> index_of(n);
    for(int k = 4; k < 2*n; k <<= 1) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        index_of[suffixes[0].index] = rank;

        for(int i = 1; i < n; i++) {
            if(suffixes[i].rank[0] == prev_rank &&
            suffixes[i].rank[1] == suffixes[i-1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }

            index_of[suffixes[i].index] = i;
        }

        for(int i = 0; i < n; i++) {
            int next_index = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (next_index < n) ? suffixes[index_of[next_index]].rank[0] : -1;
        }

        radix_sort(suffixes, 1);
        //sort(suffixes.begin(), suffixes.end(), cmp);
    }

    vector<int> suffix_array(n);
    for(int i = 0; i < n; i++) {
        suffix_array[i] = suffixes[i].index;
        //cout << suffixes[i].index << " ";
        // cout << suffixes[i].rank << " ";
        // cout << suffixes[i].next_rank << endl;
    }    

    return suffix_array;
}

vector<int> build_lcp_array(string &text, vector<int> &suffix_array) {
    int n = text.size();

    vector<int> rank(n), lcp(n);
    for(int i = 0; i < n; i++) 
        rank[suffix_array[i]] = i;

    for(int i = 0, k = 0; i < n; i++, (k > 0 ? k-- : 0)) {
        if(rank[i] == n-1) {
            k = 0; 
            continue;
        }

        int j = suffix_array[rank[i] + 1];
        while(i+k < n && j+k < n && text[i+k] == text[j+k])
            k++;
        lcp[rank[i]] = k;
    }

    return lcp;
}

int compare(string &pat, string &txt, int i) {
    int n = txt.size();
    int m = pat.size();
    
    int j;
    for(j = 0; j < m && i < n; j++, i++) {
        if(txt[i] > pat[j])
            return 1;
        else if(txt[i] < pat[j])
            return -1;
    }

    return (j == m) ? 0 : -1;
}

bool pattern_search(string &pat, string &txt, vector<int> &sa) {
    int low = 0, high = sa.size();
    while(low <= high) {
        int mid = (low + high) / 2;
        int val = compare(pat, txt, sa[mid]);
        if(val == 0) 
            return true;
        else if(val < 0) 
            low = mid + 1;
        else if(val > 0)
            high = mid - 1;
    }

    return false;
}


void solve_problem() {
    string text;
    cin >> text;

    vector<int> sa = build_suffix_array(text);
    
    int k;
    cin >> k;
    while(k--) {
        string pat;
        cin >> pat;
        if(pattern_search(pat, text, sa)) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
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

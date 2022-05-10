#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****user defined function*****/

int next_state(string &pattern, int m, int state, char c) {
    // If the character c is same as next character
    // in pattern,then simply increment state
    if(state < m && pattern[state] == c)
        return state + 1;

    // Start from the largest possible value
    // and stop when you find a prefix which is also suffix
    for(int j = state; j > 0; j--) {
        if(pattern[j-1] == c) {
            int i = 0;
            for(; i < j-1; i++) {
                if(pattern[i] != pattern[state-j+1+i])
                    break;
            }
            if(i == j-1)
                return j;
        }
    }

    return 0;
}

void solve_problem() {
    // contains only lower case english latters
    string pattern;
    cin >> pattern;

    int m = pattern.length();

    // m+1 no of state need
    // alphabet {a, b, c, d}, that's why takes 4

    // calculate transition table
    int no_of_char = 4;
    vector<vector<int>> table(m+1, vector<int>(no_of_char));
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j < no_of_char; j++) {
            table[i][pattern[j]-'a'] = next_state(pattern, m, i, pattern[j]);
        }
    }


    for(int i = 0; i <= m; i++) {
        cout << i << " -> ";
        for(int j = 0; j < no_of_char; j++) 
            cout << table[i][j] << " ";
        cout << endl;
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
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 

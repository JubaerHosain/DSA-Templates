#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int K = 26;

struct TrieNode {
    int next[K];
    int leaf = 0;
    TrieNode() {
        fill(begin(next), end(next), -1);
    }
};
vector<TrieNode> trie(1);

void add_string(string str) {
    int v = 0;
    for(char ch: str) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            // index of new node
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
        trie[v].leaf += 1;
    }
    // trie[v].leaf += 1;
}

int search_string(string str) {
    int v = 0;
    for(char ch: str) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1)
            return false;
        v = trie[v].next[c];
    }
    return trie[v].leaf;
}

void solve_problem() {
    int n, q;
    cin >> n >> q;

    while(n--) {
        string s; cin >> s;
        add_string(s);
    }

    while(q--) {
        string s; cin >> s;
        cout << search_string(s) << endl;
    }
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(6);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


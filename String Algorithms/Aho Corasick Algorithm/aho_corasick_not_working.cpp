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

struct Node {
    char pch;
    vector<int> ends;
    int go[K], next[K];
    int p = -1, link = -1;

    Node(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(go), end(go), -1);
        fill(begin(next), end(next), -1);
    }
};

vector<Node> trie(1);

void add_string(string &str, int inx) {
    int v = 0;
    for(char ch : str) {
        int c = ch - 'a';
        if(trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back(v, ch);
        }
        v = trie[v].next[c];
    }
    trie[v].ends.push_back(inx);
}

int go(int v, char ch);

int get_link(int v) {
    if(trie[v].link == -1) {
        if (v == 0 || trie[v].p == 0)
            trie[v].link = 0;
        else
            trie[v].link = go(get_link(trie[v].p), trie[v].pch);
    }
    return trie[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if(trie[v].go[c] == -1) {
        if (trie[v].next[c] != -1)
            trie[v].go[c] = trie[v].next[c];
        else
            trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return trie[v].go[c];
} 

void build_automation(vector<string> &patterns) {
    // build trie
    for(int i = 0; i < patterns.size(); i++) 
        add_string(patterns[i], i);
    // build automation
    for(int i = 0; i < trie.size(); i++) {
        for(int j = 0; j < K; j++) 
            go(i, j + 'a');
    }
}

void run_automation(string &text, int n) {
    vector<bool> ans(n, false);
    vector<bool> used(trie.size(), false);

    int v = 0;
    for(char c: text) {
        v = trie[v].go[c-'a'];
        if(!used[v]) {
            for(int i: trie[v].ends) 
                ans[i] = true;
            used[v] = true;
        }
    }

    for(int i = 0; i < n; i++) {
        if(ans[i])
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
}

void solve_problem() {
    string text; cin >> text;

    int n; cin >> n;

    vector<string> patterns(n);
    for(string &s: patterns) cin >> s;

    build_automation(patterns);

    run_automation(text, n);
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    // cout << fixed << showpoint;
    // cout << setprecision(6);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


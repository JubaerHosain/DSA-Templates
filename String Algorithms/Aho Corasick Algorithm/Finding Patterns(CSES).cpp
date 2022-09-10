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

struct Node {
    vector<int> ends;
    vector<Node*> child;
    Node *suffix_link, *output_link;
    Node() {
        ends.clear();
        child = vector<Node*>(26, NULL);
        suffix_link = output_link = NULL;
    }
};

void add_string(Node *root, string &str, int inx) {
    Node *curr = root;
    for(char ch : str) {
        char c = ch - 'a';
        if(!curr->child[c])
            curr->child[c] = new Node();
        curr = curr->child[c];
    }
    curr->ends.push_back(inx);
}

void build_automation(Node* root, vector<string> &patterns) {
    // build trie
    for(int i = 0; i < patterns.size(); i++) 
        add_string(root, patterns[i], i);
    
    // build automation
    queue<Node*> q;
    root->suffix_link = root;
    for(int i = 0; i < root->child.size(); i++) {
        if(!root->child[i]) continue;
        q.push(root->child[i]);
        root->child[i]->suffix_link = root;
    }

    while(!q.empty()) {
        Node* u = q.front(); 
        q.pop();

        for(int c = 0; c < u->child.size(); c++) {
            if(!u->child[c]) continue;
            Node *v = u->child[c];
            Node *tmp = u->suffix_link;
            while(!tmp->child[c] && tmp != root) 
                tmp = tmp->suffix_link;
            if(!tmp->child[c])
                v->suffix_link = root; 
            else    
                v->suffix_link = tmp->child[c];
            q.push(v);
        }

        if(u->suffix_link->ends.size() > 0)
            u->output_link = u->suffix_link;
        else
            u->output_link = u->suffix_link->output_link;
    }
}

void run_automation(Node* root, string &text, int n) {
    vector<bool> ans(n, false);

    set<Node*> used;

    Node* curr = root;
    for(int i = 0; i < text.length(); i++) {
        int c = text[i] - 'a';
        if(curr->child[c]) {
            curr = curr->child[c];

            if(used.count(curr)) continue;
            used.insert(curr);

            for(int inx: curr->ends)
                ans[inx] = true;
            Node* ulink = curr->output_link;
            while(ulink != NULL && ulink != root) {
                for(int inx: ulink->ends) 
                    ans[inx] = true;
                ulink = ulink->output_link;
            }
        } else {
            while(curr != root && !curr->child[c]) 
                curr = curr->suffix_link;
            if(curr->child[c]) i -= 1;
        }
    }

    for(bool it: ans) {
        if(it) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

void solve_problem() {
    string text; cin >> text;

    int n; 
    cin >> n;

    vector<string> patterns(n);
    for(string &s: patterns) cin >> s;

    Node *root = new Node();
    build_automation(root, patterns);
    run_automation(root, text, n);
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


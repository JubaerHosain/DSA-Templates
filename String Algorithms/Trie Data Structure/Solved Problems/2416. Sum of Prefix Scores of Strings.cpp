class Solution {
    struct Node {
        int end = 0;
        Node *child[26];
        Node() {
            end = 0;
            // initialize as NULL
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };
    
    void insert(Node* root, string &str) {
        Node* curr = root;
        for(char ch: str) {
            if(!curr->child[ch-'a']) 
                curr->child[ch-'a'] = new Node();
            curr = curr->child[ch-'a'];
            curr->end++;
        }
    }
    
    int search(Node* root, string &str) {
        int ans = 0;
        Node* curr = root;
        for(char ch: str) {
            curr = curr->child[ch-'a'];
            ans += curr->end;
        }
        return ans;
    }
    
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Node *root = new Node();
        for(int i = 0; i < words.size(); i++)
            insert(root, words[i]);
        
        vector<int> ans(words.size());
        for(int i = 0; i < words.size(); i++)
            ans[i] = search(root, words[i]);
        
        return ans;
    }
};

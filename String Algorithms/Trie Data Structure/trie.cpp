
/*************Trie Data Structure*************/
struct TrieNode {
    int end = 0;
    TrieNode* child[26];
};

bool isEmpty(TrieNode* root) {
    rep(i, 0, 26) {
        if(root->child[i])
            return false;
    }
    return true;
}

void insert(TrieNode* root, string &str) {
    TrieNode* curr = root;
    for(char ch: str) {
        TrieNode* node = curr->child[ch-'a'];
        if(!node) {
            node = new TrieNode();
            curr->child[ch-'a'] = node;
        }
        curr = node;
    }
    curr->end++;
}

bool search(TrieNode* root, string &str) {
    TrieNode* curr = root;
    for(char ch: str) {
        TrieNode* node = curr->child[ch-'a'];
        if(!node) 
            return false;
        curr = node;
    }
    return curr != NULL && curr->end > 0;
}

TrieNode* remove(TrieNode* root, string &str, int i) {
    if(!root) 
        return NULL;

    if(i == str.size()) {
        if(root->end > 0)
            root->end--;
        if(isEmpty(root) && root->end <= 0) {
            delete(root);
            root = NULL;
        }
        return root;
    }

    int ch = str[i] - 'a';
    root->child[ch] = remove(root->child[ch], str, i+1);
    if(isEmpty(root) && root->end <= 0) {
        delete(root);
        root = NULL;
    }

    return root;
}



/*************Trie Data Structure*************/
struct TrieNode {
    int end = 0;
    TrieNode* child[2];
};

bool isEmpty(TrieNode* root) {
    rep(i, 0, 2) {
        if(root->child[i])
            return false;
    }
    return true;
}

void insert(TrieNode* root, int n) {
    TrieNode* curr = root;
    rrep(i, 31, 0) {
        int x = (n>>i)&1;
        TrieNode* node = curr->child[x];
        if(!node) {
            node = new TrieNode();
            curr->child[x] = node;
        }
        curr = node;
    }
    curr->end++;
}

TrieNode* remove(TrieNode* root, int n, int i) {
    if(!root) 
        return NULL;

    if(i < 0) {
        if(root->end > 0)
            root->end--;
        if(isEmpty(root) && root->end <= 0) {
            delete(root);
            root = NULL;
        }
        return root;
    }

    int x = (n>>i)&1;
    root->child[x] = remove(root->child[x], n, i-1);
    if(isEmpty(root) && root->end <= 0) {
        delete(root);
        root = NULL;
    }

    return root;
}

int max_xor_sum(TrieNode* root, int n) {
    int sum = 0;
    TrieNode* curr = root;

    rrep(i, 31, 0) {
        int x = (n>>i)&1;
        if(x) {
            if(curr->child[0]) {
                sum += (2<<i);
                curr = curr->child[0];
            } else {
                curr = curr->child[1];
            }
        } else {
            if(curr->child[1]) {
                sum += (2<<i);
                curr = curr->child[1];
            } else {
                curr = curr->child[0];
            }
        }
    }

    return sum;
}


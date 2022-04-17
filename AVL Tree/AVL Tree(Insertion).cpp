#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
struct Node {
    int key, height;
    Node *left, *right;
    Node(int _key) {
        key = _key;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int get_height(Node *root) {
    if(root == NULL)
        return 0;
    return root->height;
}

int get_bfactor(Node *root) {
    if(root == NULL)
        return 0;
    return get_height(root->left) - get_height(root->right);
}

Node* left_rotate(Node* root) {
    Node *new_root = root->right;
    Node *tmp = new_root->left;
 
    // Perform rotation
    new_root->left = root;
    root->right = tmp;
 
    // Update heights
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    new_root->height = 1 + max(get_height(new_root->left), get_height(new_root->right));
 
    // Return new root
    return new_root;
}

Node* right_rotate(Node* root) {
    Node *new_root = root->left;
    Node *tmp = new_root->right;
 
    // Perform rotation
    new_root->right = root;
    root->left = tmp;
 
   // Update heights
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    new_root->height = 1 + max(get_height(new_root->left), get_height(new_root->right));
 
    // Return new root
    return new_root;
}

Node* insert(Node *root, int key) {
    if(root == NULL)
        return new Node(key);

    //equal values not allowed
    if(key < root->key)
        root->left = insert(root->left, key);
    else if(key > root->key)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    int bfactor = get_bfactor(root);

    // Left Left Case
    if (bfactor > 1 && key < root->left->key)
        return right_rotate(root);
 
    // Right Right Case
    if (bfactor < -1 && key > root->right->key)
        return left_rotate(root);
 
    // Left Right Case
    if (bfactor > 1 && key > root->left->key) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
 
    // Right Left Case
    if (bfactor < -1 && key < root->right->key) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
 
    return root;
}

void solve_problem() {
    Node *root = NULL;
    for(int i = 1; i < 1000000; i++)
        root = insert(root, i);
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

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

Node* min_node(Node *root) {
    Node *temp = root;
    while(temp != NULL && temp->left != NULL)
        temp = temp->left;
    return temp;
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

Node* insert_node(Node *root, int key) {
    if(root == NULL)
        return new Node(key);

    //equal values not allowed
    if(key < root->key)
        root->left = insert_node(root->left, key);
    else if(key > root->key)
        root->right = insert_node(root->right, key);
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

Node* delete_node(Node *root, int key) {
    if(root == NULL)
        return root;

    if(key < root->key) {
        root->left = delete_node(root->left, key);
    }
    else if(key > root->key) {
        root->right = delete_node(root->right, key);
    }
    else {
        if(root->left == NULL || root->right == NULL) {
            Node *temp = root->left ? root->left : root->right;
            //no child case
            if(temp == NULL) {
                temp = root;
                root = NULL;
            } 
            else {
                //one child case
                //copy the values to root
                *root = *temp; 
            }
            //free the unusable memory
            free(temp);
        }
        else {
            //two child case
            Node *temp = min_node(root->right);
            root->key = temp->key;
            root->right = delete_node(root->right, temp->key);
        }
    }

    //if tree had one node
    //then it has deleted
    if(root == NULL) 
        return root;

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    int bfactor = get_bfactor(root);
  
    // Left Left Case
    if (bfactor > 1 && get_bfactor(root->left) >= 0)
        return right_rotate(root);
 
    // Left Right Case
    if (bfactor > 1 && get_bfactor(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
 
    // Right Right Case
    if (bfactor < -1 && get_bfactor(root->right) <= 0)
        return left_rotate(root);
 
    // Right Left Case
    if (bfactor < -1 && get_bfactor(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
 
    return root;
}

void solve_problem() {
    Node *root = NULL;
    for(int i = 1; i < 100; i++)
        root = insert_node(root, i);
    
    for(int i = 1; i < 100; i++)
        root = delete_node(root, i);
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

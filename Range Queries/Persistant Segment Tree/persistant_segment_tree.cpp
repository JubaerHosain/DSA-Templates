// PSEGTREE - Make Versions in Segment Tree(SPOJ)




#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

/*****Persistant Segment Tree*****/
const int N = 1e5 + 5;
struct Node {
    int val;
    Node *left, *right;
    Node() {}
    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

int arr[N];        // initial array
Node *version[N];

void build(Node *root, int left, int right) {
    if(left == right) {
        root->val = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    root->left = new Node(0, NULL, NULL);
    root->right = new Node(0, NULL, NULL);
    build(root->left, left, mid);
    build(root->right, mid+1, right);
    root->val = root->left->val + root->right->val;
}

void update(Node *prev, Node *curr, int left, int right, int pos, int val) {
    if(pos > right || pos < left || left > right)
        return;
    else if(left == right) {
        curr->val = prev->val + val; // add value to the current node
        return;
    }
    int mid = (left + right) / 2;
    if(pos <= mid) {
        // link to right child of previous version
        curr->right = prev->right;
        // create new node for current version
        curr->left = new Node(0, NULL, NULL);
        update(prev->left, curr->left, left, mid, pos, val);
    } else {
        // link to left child of previous version
        curr->left = prev->left;
        // create new node for current version
        curr->right = new Node(0, NULL, NULL);
        update(prev->right, curr->right, mid+1, right, pos, val);
    }
    // calculating data for current version
    // by combining previous version and current modification
    curr->val = curr->left->val + curr->right->val;
}

int query(Node *root, int sl, int sr, int l, int r) {
    if(sl > r || sr < l)                    // no overlap;
        return 0;
    else if(sl >= l && sr <= r)             // total overlap
        return root->val;
    int mid = (sl + sr) / 2;
    return query(root->left, sl, mid, l, r) + query(root->right, mid+1, sr, l, r);
}


 
/*****User defined function*****/

void solve_problem() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    for(int i = 0; i < N; i++)
        version[i] =  new Node(0, NULL, NULL);

    build(version[0], 0, n-1);

    int q;
    cin >> q;
    int k = 0;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            k += 1;
            int i, pos, val;
            cin >> i >> pos >> val;
            
            update(version[i], version[k], 0, n-1, pos-1, val);
        } else {
            int i, l, r;
            cin >> i >> l >> r;
            cout << query(version[i], 0, n-1, l-1, r-1) << endl;
        }
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
    cout << setprecision(15);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


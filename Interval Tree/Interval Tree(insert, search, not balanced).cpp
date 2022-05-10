#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

 
/*****User defined function*****/
struct Interval {
    int low, high;
    Interval(int _low, int _high) {
        low = _low;
        high = _high;
    }
};

struct Node {
    Interval *interval;
    int max;
    Node *left, *right;
    Node(Interval *_interval) {
        left = NULL;
        right = NULL;
        interval = _interval;
        max = _interval->high;
    }
};

bool overlaped(Interval *a, Interval *b) {
    return a->low <= b->high && a->high >= b->low;
}

Node* insert_interval(Node *root, Interval *interval) {
    if(root == NULL)
        return new Node(interval);

    //bcz low as key value
    if(interval->low < root->interval->low) 
        root->left = insert_interval(root->left, interval);
    else 
        root->right = insert_interval(root->right, interval);

    root->max = max(root->max, interval->high);
    
    return root;
}

//returns a single interval. (how to find all intervals overlaped?)
Interval* overlap_search(Node *root, Interval *interval) {
    if(root == NULL)
        return NULL;
    
    if(overlaped(root->interval, interval))
        return root->interval;

    //max is the maximum high valu of its subtree(including itself)
    if(root->left != NULL && root->left->max >= interval->low)
        return overlap_search(root->left, interval);
    else
        return overlap_search(root->right, interval);
}

void solve_problem() {
    Node *root = NULL;
    for(int i = 1; i < 100; i++) {
        root = insert_interval(root, new Interval(i, 10+i));
        //cout << i << " " << i+10 << endl;
    }

    Interval *in = overlap_search(root, new Interval(20, 22));
    cout << in->low << " " << in->high << endl;
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

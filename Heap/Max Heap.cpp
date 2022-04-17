#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int heapsize = 0;
vector<int> heap;

void max_heapify(int i) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int max_index = i;

    if(left < heapsize && heap[left] > heap[max_index])
        max_index = left;
    if(right < heapsize && heap[right] > heap[max_index])
        max_index = right;

    if(max_index != i) {
        swap(heap[max_index], heap[i]);
        max_heapify(max_index);
    }
}

void insert_key(int val) {
    //insert at the end
    ++heapsize;
    int i = heapsize - 1;
    heap.push_back(val);

    //max heapify bottom to top
    int parent = (i-1) / 2;
    while(i != 0 && heap[parent] < heap[i]) {
        swap(heap[i], heap[parent]);
        i = parent;
        parent = (i-1) / 2;
    }
}

int extract_max() {
    if(heapsize <= 0) {
        return INT_MAX;
    }
    else if(heapsize == 1){
        heapsize--;
        int mn = heap.back();
        heap.pop_back();
        return mn;
    }

    int root = heap[0];
    heap[0] = heap[heapsize-1];
    heapsize--;
    heap.pop_back();
    //max heapify top to bottom
    max_heapify(0);

    return root;
}

void solve_problem() {
    for(int i = 1; i <= 100; i++)
        insert_key(i);
    
    while(heapsize) 
        cout << extract_max() << endl;
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

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
int heapsize = 0;
vector<int> heap;

void min_heapify(int i) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int min_index = i;

    if(left < heapsize && heap[left] < heap[min_index])
        min_index = left;
    if(right < heapsize && heap[right] < heap[min_index])
        min_index = right;

    if(min_index != i) {
        swap(heap[min_index], heap[i]);
        min_heapify(min_index);
    }
}

void insert_key(int val) {
    //insert at the end
    ++heapsize;
    int i = heapsize - 1;
    heap.push_back(val);

    //min heapify bottom to top
    int parent = (i-1) / 2;
    while(i != 0 && heap[parent] > heap[i]) {
        swap(heap[i], heap[parent]);
        i = parent;
        parent = (i-1) / 2;
    }
}

int extract_min() {
    if(heapsize <= 0) {
        return INT_MIN;
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
    //min heapify top to bottom
    min_heapify(0);

    return root;
}

void solve_problem() {
    for(int i = 100; i > 0; i--)
        insert_key(i);
    
    while(heapsize) 
        cout << extract_min() << endl;
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

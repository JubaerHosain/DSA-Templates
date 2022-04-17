time and space complexity will affect with k*N*log(k*N) size(if put all values in a min heap), 
to avoid space complexity use min Heap in this case time complexity will change to k*N*log(K) time and O(1) size . 

Another way is to marge two list at a time and result with the third one and so on(this will take n^2 complexity)

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/

void solve_problem() {
    int n;
    cin >> n;

    vii lists(n);
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for(int j = 0; j < m; j++) {
            int val;
            cin >> val;
            lists[i].push_back(val);
        }
    }

    // we can use pair<pair<int, int>, int> instead of inxof
    vector<int> inxof(n, 0);
    priority_queue<pii, vector<pii>, greater<pii>> min_heap;
    for(int i = 0; i < n; i++) 
        min_heap.push({lists[i][0], i});

    //cout << min_heap.size() << endl;

    vector<int> ans;
    // at any moment heap will contain at most k(number of list) element
    while(!min_heap.empty()) {
        auto curr = min_heap.top();
        min_heap.pop();
        ans.push_back(curr.first);
        if(inxof[curr.second] + 1 < lists[curr.second].size()) 
            min_heap.push({lists[curr.second][inxof[curr.second]+1], curr.second});
        inxof[curr.second] += 1;
    }

    for(int i: ans)
        cout << i << " ";
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
    cout << setprecision(5);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();
    
 
    return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
void counting_sort(vector<int> &vect) {
    int mx = *max_element(vect.begin(), vect.end());
    vector<int> count(mx+1, 0);

    for(int i = 0; i < vect.size(); i++) 
        ++count[vect[i]];

    for(int i = 1; i < count.size(); i++)
        count[i] += count[i-1];

    vector<int> temp(vect.size());
    for(int i = 0; i < temp.size(); i++) {
        temp[count[vect[i]]-1] = vect[i];
        --count[vect[i]];
    }

    //for stable sort, maitains relative order
    // for(int i = temp.size()-1; i >= 0; i--) {
    //     temp[count[vect[i]]-1] = vect[i];
    //     --count[vect[i]];
    // }

    for(int i = 0; i < vect.size(); i++) 
        vect[i] = temp[i];;
}

void solve_problem() {
    int n;
    cin >> n;

    vector<int> vect(n);
    for(int i = 0; i < n; i++)
        cin >> vect[i];

    counting_sort(vect);

    for(int i = 0; i < n; i++) 
        cout << vect[i] << " ";
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

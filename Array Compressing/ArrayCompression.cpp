#include<bits/stdc++.h>
using namespace std;

// Array size N <= 1e5;
// a[i] <= 1e9;
// Now i want to use a[i] as index;
// compress a[i]'s to smaller number

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = 0;
    }

    int cnt = 0; 
    for(auto &it: mp) 
        it.second = cnt++;

    // compressed array
    vector<int> b(n); 
    for(int i = 0; i < n; i++) {
        b[i] = mp[a[i]];
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << b[i] << " ";
}












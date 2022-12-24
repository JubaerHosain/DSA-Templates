#include<bits/stdc++.h>
using namespace std;

int main() {
    // n is power of two
    int n = 8;
    vector<int> a({0, 1, 2, 3, 4, 5, 6, 7});
    
    // j = reverse bit representation of i with log2(n) number of bit
    for(int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for(; (j&bit); bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
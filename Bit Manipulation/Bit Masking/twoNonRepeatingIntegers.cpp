#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, *arr, x = 0, y = 0, res = 0;
    cin >> n;

    arr = new int[n];
    for(int i = 0; i < n;  i++){
        cin >> arr[i];
        res ^= arr[i];
    }

    int mask = res & -res;
    for(int i = 0; i < n; i++){
        if(arr[i] & mask){
            x ^= arr[i];
        }
        else{
            y ^= arr[i];
        }
    }

    cout << endl << x << endl << y;
}

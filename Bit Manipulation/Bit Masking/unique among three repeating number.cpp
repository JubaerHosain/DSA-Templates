#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, *arr, bit[32] = {0};

    cin >> n;
    arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        int num = arr[i];
        int j = 0;
        while(num){
            bit[j++] += (num&1);
            num = num>>1;
        }
    }

    int result = 0;
    for(int i = 0; i < 32; i++){
        bit[i] %= 3;
        result += (bit[i] * (1<<i));
    }

    cout << result;
}

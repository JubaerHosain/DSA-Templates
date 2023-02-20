#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, result = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        result ^= num;  //xor operation destroys duplicate values
    }

    cout << result;
}

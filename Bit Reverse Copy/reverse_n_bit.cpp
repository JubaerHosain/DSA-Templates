#include<bits/stdc++.h>
using namespace std;

// reversed only actual binary representation, not leading zero's
unsigned int reverse_bits(unsigned int n) {
    unsigned int rev = 0;
    while (n > 0) {
        rev <<= 1;
        if (n & 1)
            rev ^= 1;
        n >>= 1;
    }
    return rev;
}

// reverse n bit of number num
unsigned int reverse_n_bits(unsigned int num, int n) {
    unsigned int rev = 0;
    for(int i = 1; i <= n; i++) {
        rev <<= 1;
        if(num & 1) 
            rev ^= 1;
        num >>= 1;
    }
    return rev;
}
 
/*****main function*****/
int main() {
    
    // cout << reverse_bits(2) << endl;
    // cout << reverse_bits(3) << endl;
    // cout << reverse_bits(4) << endl;
    // cout << reverse_bits(6) << endl;

    cout << reverse_n_bits(15, 4) << endl;

    return 0;
} 


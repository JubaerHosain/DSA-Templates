// In this hashing technique, the hash of a string is calculated as:
// hash = (s[0]*P^{0} + s[1]*P^{1} + ....s[m]*P^{m}) mod M      
// Where P and M are some positive numbers.  And s[0], s[1], s[2] … s[n-1] are 
//the values assigned to each character in English alphabet (a->1, b->2, … z->26). 

// Appropriate values for P and M :
// P: The value of P can be any prime number roughly equal to the number of different characters used. 
// For example: if the input string contains only lowercase letters of the English alphabet, then P = 31 is the appropriate value of P. 
// If the input string contains both uppercase and lowercase letters, then P = 53 is an appropriate option.
// M: the probability of two random strings colliding is inversely proportional to m, Hence m should be a large prime number. 
// M = 10 ^9 + 9 is a good choice.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
int mod = 1e9+9;
const int N = 5e2+5;

void solve_task() {
    string text;
    cin >> text;

    ll hash_value = 0;
    ll p = 31, power = 1;
    for(char ch: text) {
        hash_value = (hash_value + (ch-'a'+1) * power) % mod;
        power = (power * p) % mod;
    }
    
    cout << "Hash value is: " << hash_value << endl;
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
    while(test--) {
        solve_task();
    }

    return 0;
} 

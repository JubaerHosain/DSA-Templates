#include<bits/stdc++.h>
using namespace std;
#define all(v)                  v.begin(), v.end()
#define rall(v)                 v.rbegin(), v.rend()
#define des()                   greater<int>()
#define rep(i, a, n)            for(ll i = a; i < n; i++)  
#define rrep(i, n, a)           for(ll i = n; i >= a; i--)
#define pqueue                  priority_queue
#define umap                    unordered_map
#define uset                    unordered_set
#define pub                     push_back
#define pob                     pop_back  
#define endl                    '\n' //in interactive problem should not use this
#define println                 cout << endl
#define scan_array(arr, n)      for(ll i = 0; i < n; i++) { cin >> arr[i]; }
#define print_array(arr, n)     for(ll i = 0; i < n; i++) { cout << arr[i] << " "; } println;
#define print(var)              cout << var << endl;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
const int p = 1e9+7;
const int eps = 1e-9;
const int inf = INT_MAX;
const int N = 1e6+10;

/*************Sieve of Eratosthenes*************/
vector<bool> prime(N, false);

void prime_sieve() {
    prime[2] = true;                        //2 is a prime number
    for(ll i = 3; i <= N; i+=2) {          //mark all odd as true
        prime[i] = true;                    //because prime numbers are also odd
    }

    for(ll i = 3; i*i <= N; i+=2) {
        if(prime[i]) {                              //if is prime number 
            for(ll j = i*i; j <= N; j+=i) {        //mark all multiple as false
                prime[j] = false;
            }
        }
    }
}

/*************User defined function*************/
void solve() {
    int cnt = 0;
    rep(i, 1, 1000001) {
        if(prime[i]) cnt++;
    }

    print(cnt);
}


/*************main function*************/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

    prime_sieve();

    int test = 1;
    cin >> test;
    while(test-- > 0) {
        solve();
    }

    return 0;
}    

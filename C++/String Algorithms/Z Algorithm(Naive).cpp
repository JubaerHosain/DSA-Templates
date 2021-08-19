#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****User defined function*****/
int mod = 1e9+7;
const int N = 1e5+5;

vector<int> compute_zfunction(string &text) {
    vector<int> z(text.size());

    int n = text.size();
    for(int i = 1; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(text[j] != text[j-i])
                break;
            else    
                z[i]++;
        }
    }

    return z;
}

void solve_task() {
    string text;
    cin >> text;

    vector<int> z = compute_zfunction(text);

    for(int i: z)
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
    cout << setprecision(16);

    int test = 1;
    //cin >> test;
    while(test--) {
        solve_task();
    }

    return 0;
} 

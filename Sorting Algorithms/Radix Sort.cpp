#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
void counting_sort(vector<int> &vect, int exp) {
    vector<int> count(10, 0);

    for(int i = 0; i < vect.size(); i++) 
        ++count[(vect[i] / exp) % 10];

    for(int i = 1; i < count.size(); i++)
        count[i] += count[i-1];

    //for stable sort = maintain relative order
    vector<int> temp(vect.size());
    for(int i = temp.size()-1; i >= 0; i--) {
        temp[count[(vect[i] / exp) % 10] - 1] = vect[i];
        --count[(vect[i] / exp) % 10];
    }

    for(int i = 0; i < vect.size(); i++) 
        vect[i] = temp[i];;
}

void radix_sort(vector<int> &vect) {
    int mx = *max_element(vect.begin(), vect.end());

    for(int exp = 1; mx / exp > 0; exp *= 10)
        counting_sort(vect, exp);
}

void solve_problem() {
    int n;
    cin >> n;

    vector<int> vect(n);
    for(int i = 0; i < n; i++)
        cin >> vect[i];

    radix_sort(vect);

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





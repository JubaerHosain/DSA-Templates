#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
struct suffix {
    int index;
    string suffix_str;
};

bool cmp(const suffix a, const suffix b) {
    return a.suffix_str < b.suffix_str;
}

void solve_problem() {
    string input, pattern;
    cin >> input >> pattern;

    vector<suffix> suffixes(input.size());
    for(int i = 0; i < input.size(); i++) {
        suffixes[i].index = i; 
        suffixes[i].suffix_str = input.substr(i);
    }

    sort(suffixes.begin(), suffixes.end(), cmp);

    for(int i = 0; i < input.size(); i++) {
        cout << suffixes[i].index << " " << suffixes[i].suffix_str << endl;
    }

    //this algorithm only able to find single occurrence
    bool flag = false;
    int left = 0, right = suffixes.size()-1;
    while(left <= right) {
        int mid = (left + right) / 2;
        string mid_str = input.substr(suffixes[mid].index, pattern.size());
        
        if(pattern == mid_str) {
            cout << "Pattern found at position: " << suffixes[mid].index << endl;
            flag = true;
            break;
        }
        else if(pattern < mid_str) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    if(!flag) cout << "Not found!" << endl;
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





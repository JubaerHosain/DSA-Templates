#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
vector<int> manachers_algo(string &text) {
    int n = text.size();
    vector<int> lps_array(n, 1);
    
    int centre = 0, right = 0;
    for(int i = 1; i < n-1; i++) {
        int mirror = centre - (i-centre);
        if(i < right)
            lps_array[i] = min(lps_array[mirror], right-i);

        while(i - lps_array[i] >= 0 && i + lps_array[i] <= n-1
        && text[i - lps_array[i]] == text[i + lps_array[i]]) 
            lps_array[i]++;

        if(i + lps_array[i] > right) {
            centre = i;
            right = i + lps_array[i];
        }
    } 

    return lps_array;
}

void solve_problem() {
    string str;
    cin >> str;

    string text = "#";
    int n  = str.size();
    for(int i = 0; i < n; i++) {
        text += str[i];
        text += "#";
    }

    // vector<int> lps_odd = manachers_algo(str);
    vector<int> lps_even = manachers_algo(text);

    // cout << str << endl;
    // for(int i = 0; i < lps_odd.size(); i++)
    //     cout << lps_odd[i] << " ";
    // cout << endl;

    //cout << text << endl;
    // for(int i = 0; i < lps_even.size(); i++)
    //     cout << lps_even[i] << " ";
    // cout << endl;

    int mx_len = 0, mx_inx = 0;
    for(int i = 0; i < lps_even.size(); i++) {
        int curr = ((lps_even[i]*2) - 2) / 2;
        if(curr > mx_len ) {
            mx_len = curr;
            mx_inx = i;
        }
        // cout << curr << " ";
    }
    // cout << endl;

    // cout << mx_inx << endl;
    // cout << mx_len << endl;

    int first_inx = mx_inx - mx_len;
    string ans = text.substr(first_inx, 2*mx_len+1);

    for(int i = 0;  i < ans.size(); i++)
        if(ans[i] != '#') cout << ans[i];
    cout << endl;
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

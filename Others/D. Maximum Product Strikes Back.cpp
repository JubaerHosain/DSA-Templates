#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'//notforinter
#define all(v)        v.begin(), v.end()
#define print(var)    cout << var << endl
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rrep(i, n, s) for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const int N = 5e5+5;

pair<int, pair<int, int>> get_max(vector<int> &a, int left, int right, pair<int, pair<int, int>> &ans) {
    int n = a.size();
    int two = 0;
    int negative = 0;
    for(int i = left; i < right; i++) {
        if(a[i] < 0)
            negative += 1;
        if(abs(a[i]) == 2)
            two += 1;
    }

    if(negative%2 == 0) {
        if(ans.first < two) {
            ans.first = two;
            ans.second.first = left;
            ans.second.second = n - right;
        }
        return ans;
    }
    else {
        // remove 1 negative from left
        int tmp_two = two;
        int i = left;
        for(; i < right; i++) {
            if(a[i] < 0) {
                if(abs(a[i]) == 2)
                    tmp_two -= 1;
                break;
            }
            else if(a[i] == 2) {
                tmp_two -= 1;
            }
        }

        pair<int, pair<int, int>> tmp_ans = {tmp_two, {i+1, n-right}};
        //cout << "->" << tmp_two << " " << i+1 << " " << n-right << endl;

        // remove 1 negative from right
        i = right - 1;
        tmp_two = two;
        for(; i >= left; i--) {
            if(a[i] < 0) {
                if(abs(a[i]) == 2)
                    tmp_two -= 1;
                break;
            }
            else if(a[i] == 2) {
                tmp_two -= 1;
            }
        }

        if(tmp_ans.first < tmp_two) {
            tmp_ans.first = tmp_two;
            tmp_ans.second.first = left;
            tmp_ans.second.second = n - i;
        }

        if(ans.first < tmp_ans.first) 
            return tmp_ans;
        else 
            return ans;
    }
}

void solve_problem() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> zero;
    zero.push_back(-1);
    for(int i = 0; i < n; i++) {
        if(a[i] == 0)
            zero.push_back(i);
    }
    zero.push_back(n);

    // {mx, (l, r)} 
    pair<int, pair<int, int>> ans = {0, {0, n}};
    for(int i = 1; i < zero.size(); i++) {
        //cout << zero[i-1] + 1 << " " << zero[i] << endl;
        ans = get_max(a, zero[i-1]+1, zero[i], ans);
    }

    cout << ans.second.first << " " << ans.second.second << endl;
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
    cout << setprecision(5);
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();
    
 
    return 0;
} 

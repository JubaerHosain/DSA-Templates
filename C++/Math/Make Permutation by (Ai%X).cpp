problem link: https://www.codechef.com/problems/MAGICMOD

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****user defined function*****/

vector<int> getFactors(ll n, int st) {
    vector<int> a;
    for(ll i = st; i * i <= n; i++) {
        if(n%i == 0) {
            a.push_back(i);
            if(i != n/i && n/i > st)
                a.push_back(n/i);
        }
    }
    return a;
}

void solve_problem() {
    ll n;
    cin >> n;

    ll sum = 0;
    vector<int> cnt(n+1, 0);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if(a[i] <= n)
            cnt[a[i]]++;
    }

    int ans = -1;
        for(int i = 1; i <= n; i++) {
            if(cnt[i] == 1) 
                ans = n+1;
            else {
                ans = -1;
                break;
            }
        }
        if(ans != -1 && ans <= 2e7) {
            cout << "YES" << " " << ans << endl;
            return;
        }

    

    ll tot = (n * (n+1)) / 2;
    
    if(sum < tot) {
        cout << "NO" << endl;
        return;
    } 

    ll q = sum - tot;
    vector<int> factors = getFactors(q, n);

    for(int fact: factors) {
        if(fact > 2e7) continue;
        if(fact <= n) continue;

        vector<int> cnt(n+1, 0);
        for(int val: a) {
            int rem = val%fact;
            if(rem >= 1 && rem <= n) 
                cnt[rem]++;
        }
        
        int ans = -1;
        for(int i = 1; i <= n; i++) {
            if(cnt[i] == 1) 
                ans = fact;
            else {
                ans = -1;
                break;
            }
        }
        if(ans != -1 && ans <= 2e7) {
            cout << "YES" << " " << ans << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
    cin >> test;
    while(test--) solve_problem();

    return 0;
} 

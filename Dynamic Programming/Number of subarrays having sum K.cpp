#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve_problem() {
    vector<int> a = { 10, 2, -2, -20, 10 };
    int n = a.size(), k = -10;

    ll psum = 0, ans = 0;
    map<ll, int> mp;
    for(int i = 0; i < n; i++) {
        psum += a[i];
        if(psum == k)
            ans += 1;
        if(mp.count(psum-k))
            ans += mp[psum-k];
        mp[psum]++;
    }

    cout << ans << endl;
}

int main() {
    solve_problem();
    return 0;
}
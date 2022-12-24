// Spoj Problem

#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
#define all(v)   v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
 
const ld PI = 2 * acos(0.0);
typedef complex<ld> Complex;
 
void fft(vector<Complex> &p, bool invert) {
    int n = p.size();
 
    // re arrange leaf nodes, it is called the bit-reversal permutation
    // j = reverse bit representation of i with log2(n) number of bit
    for(int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for(; (j&bit); bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) swap(p[i], p[j]);
    }
 
    for(int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        Complex wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len) {
            Complex w(1);
            for(int j = 0; j < len / 2; j++) {
                Complex u = p[i+j], v = p[i+j+len/2] * w;
                p[i+j] = u + v, p[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) 
        for (Complex &x : p) x /= n;
}
 
vector<int> multiply(vector<int> &a, vector<int> &b) {
    vector<Complex> fa(all(a)), fb(all(b));
    
    int n = 1;
    int degr = a.size() + b.size();
    while (n < degr) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
 
    for(int i = 0; i < n; i++)
        fa[i] *= fb[i];
 
    fft(fa, true);
 
    vector<int> result(n);
    for(int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
 
    return result;
}
 
string poly_to_num(vector<int> &a) {
    int carry = 0;
    int n = a.size();
    for(int i = 0; i < n; i++) {
        a[i] += carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    
    // check if carry > 0 or not if degr = a.size() + b.size() - 1
    // think about input like 9 * 9, res size should 2, but degr becomes 1
    // it may happen if use [degr = a.size() + b.size() - 1] at multiply function
 
    while(a.size() > 1 && a.back() == 0)
        a.pop_back();
 
    string ans;
    for(int &i: a) ans += to_string(i);
 
    reverse(ans.rbegin(), ans.rend());
 
    return ans;
}
 
void solve_problem() {
    string s1, s2;
    cin >> s1 >> s2;
 
    reverse(s1.rbegin(), s1.rend());
    reverse(s2.rbegin(), s2.rend());
 
    // polynomial in form of a0 + a1*x + a2*x^2 + ..... + an-1*x^(n-1)
    int n = s1.length();
    int m = s2.length();
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) 
        a[i] = s1[i] -'0';
 
    for(int j = 0; j < m; j++) 
        b[j] = s2[j] -'0';
 
    vector<int> res = multiply(a, b);
 
    cout << poly_to_num(res) << endl;
    
}
 
/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif 
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 
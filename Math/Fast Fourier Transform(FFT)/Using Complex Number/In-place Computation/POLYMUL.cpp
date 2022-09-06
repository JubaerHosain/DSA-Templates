// SPOJ Problem

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
 
    // re arrange leaf nodes
    // it is called the bit-reversal permutation
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
 
vector<ll> multiply(vector<int> &a, vector<int> &b) {
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
 
    vector<ll> result(n);
    for(int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
 
    return result;
}
 
void solve_problem() {
    int n; cin >> n;
 
    vector<int> a(n+1), b(n+1);
    for(int i = 0; i <= n; i++) 
        cin >> a[i];
 
    for(int i = 0; i <= n; i++) 
        cin >> b[i];
 
    vector<ll> res = multiply(a, b);
 
    int N = 2*n;
    for(int i = 0; i <= N; i++)
        cout << res[i] << " ";
    cout << endl;
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
 
 
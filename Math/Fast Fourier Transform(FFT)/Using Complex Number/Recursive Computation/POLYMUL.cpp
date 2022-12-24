// SPOJ Problem (TLE in recursive approach)

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
 
void fft(valarray<Complex> &p, bool inverse = false) {
    if(p.size() <= 1) return;

    int n = p.size();
    valarray<Complex> f = p[slice(0, n/2, 2)];  // all even position
    valarray<Complex> g = p[slice(1, n/2, 2)];  // all odd position

    // do fft on both f and g
    fft(f, inverse); 
    fft(g, inverse);

    Complex w = Complex(1, 0);
    //a primitive root of x^n = 1 is e^(2pi/n)
    Complex omega_n = exp(Complex(0, 2*PI/n));

    // this condition for inverse fft
    if(inverse) omega_n = Complex(1, 0) / omega_n;

    for(int k = 0; k < n/2; k++) {
        Complex add = w * g[k];      
        // this is p(x)
        p[k] = f[k] + add;
        // note that p(-x) should be in (x+n/2)th position
        p[k+n/2] = f[k] - add;
        w *= omega_n;
    }
}

void inverse_fft(valarray<Complex> &p) {
    fft(p, true);
    // divide each element by p.size()
    p /= p.size();
}

 
vector<ll> multiply(vector<int> &a, vector<int> &b) {
    
    int n = 1;
    int degr = a.size() + b.size();
    while (n < degr) 
        n <<= 1;

    valarray<Complex> fa(n), fb(n);
    for(int i = 0; i < n; i++) {
        if(i < a.size())
            fa[i] = Complex(a[i], 0);
        else
            fa[i] = Complex(0, 0);
    }

    for(int i = 0; i < n; i++) {
        if(i < a.size())
            fb[i] = Complex(b[i], 0);
        else
            fb[i] = Complex(0, 0);
    }
 
    fft(fa);
    fft(fb);
 
    for(int i = 0; i < n; i++)
        fa[i] *= fb[i];
 
    inverse_fft(fa);
 
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
 
    cout << fixed << showpoint;
    cout << setprecision(15);
 
    int test = 1;
    cin >> test;
    while(test--) solve_problem();
 
    return 0;
} 
 
 

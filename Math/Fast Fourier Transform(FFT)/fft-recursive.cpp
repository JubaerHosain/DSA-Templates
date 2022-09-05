#include<bits/stdc++.h>
using namespace std;
#define endl          '\n'
#define all(v)        v.begin(), v.end()
#define rep(i, s, n)  for(int i = s; i <= n; i++)
#define rev(i, n, s)  for(int i = n; i >= s; i--)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
 
/*****User defined function*****/
const ld PI = 2 * acos(0.0);
typedef complex<ld> Complex;

void fft(valarray<Complex> &p, bool inverse = 0) {
    if(p.size() <= 1) return;

    int n = p.size();
    valarray<Complex> f = p[slice(0, n/2, 2)];  // all even position
    valarray<Complex> g = p[slice(1, n/2, 2)];  // all odd position

    // do fft on both f and g
    fft(f, inverse); fft(g, inverse);

    Complex w = Complex(1, 0);
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
    fft(p, 1);
    // divide each element by p.size()
    p /= p.size();
}

vector<int> multiply(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    int degr = n + m - 1;         // degree of result
    int N = 1;                    // rounding up to nearest 2^x
    while(N < degr) N <<= 1;

    valarray<Complex> x(N), y(N), z(N);

    // resize first polynomial by inserting 0
    for(int i = 0; i < n; i++) x[i] = Complex(a[i], 0);
    for(int i = n; i < N; i++) x[i] = Complex(0, 0);

    // resize second polynomial by inserting 0
    for(int i = 0; i < m; i++) y[i] = Complex(b[i], 0);
    for(int i = m; i < N; i++) y[i] = Complex(0, 0);

    // do fft on both polynomial
    fft(x), fft(y);

    // multiply in Point-Value Form
    for(int i = 0; i < N; i++) z[i] = x[i] * y[i];

    // do inverse fft on resultant polynomial
    inverse_fft(z);

    // precision problem may occur, round to nearest integer
    vector<int> ans(N);
    for(int i = 0; i < N; i++) ans[i] = z[i].real() + 0.5;

    // remove trailing 0's
    while(ans.size() > 1 && ans.back() == 0) ans.pop_back();

    return ans;
}


void solve_problem() {
    int n, m;
    cin >> n >> m;

    // polynomial in form of a0 + a1*x + a2*x^2 + ..... + an-1*x^(n-1)
    
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];

    vector<int> res = multiply(a, b);

    for(int i: res) cout << i << " ";
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
    cout << setprecision(6);
 
    int test = 1;
    // cin >> test;
    while(test--) solve_problem();

    return 0;
} 


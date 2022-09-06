// from Rezwan's CP Blog


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

typedef complex <long double> Complex;
typedef valarray <Complex> ValComplex;

const long double PI = 2 * acos(0.0);

void fft(ValComplex &p, bool inverse = 0) {
  int n = p.size();
  if(n <= 1) return;

  ValComplex f = p[slice(0, n/2, 2)],
             g = p[slice(1, n/2, 2)];

  // splice(a, b, c) will return number in indexes
  // a, a + c, a + 2c, .... a + (b-1)c  

  fft(f, inverse); fft(g, inverse); // FFT for F and G

  Complex omega_n = exp(Complex(0, 2 * PI / n)), w = 1;
  if(inverse) omega_n = Complex(1, 0) / omega_n;

  for(int k = 0; k < n / 2; k++) {
    // Here w = omega_n^k
    Complex add = w * g[k];   
    // this is p(x)
    p[k]       = f[k] + add;  
    // Note that p(-x) should be in (x+n/2)th position
    p[k + n/2] = f[k] - add;  
    w *= omega_n;
  }
}
void ifft(ValComplex &p) {
  fft(p, 1);
  p /= p.size(); // Divide each element by p.size()
}

vector<int> multiply(vector<int> a, vector<int> b) {
  int n = a.size(), m = b.size();
  int t = n + m - 1, sz = 1; // t is degree of R
  while(sz < t) sz <<= 1;  // rounding to nearest 2^x

  ValComplex x(sz), y(sz), z(sz);
  // Resize first polynomial by inserting 0.
  for(int i = 0; i < n; i++) x[i] = Complex(a[i], 0);
  for(int i = n; i < sz; i++) x[i] = Complex(0, 0);

  // Resize second polynomial by inserting 0.
  for(int i = 0; i < m; i++) y[i] = Complex(b[i], 0);
  for(int i = m; i < sz; i++) y[i] = Complex(0, 0);

  fft(x); fft(y);   // Do fft on both polynomial
  // Multiply in Point-Value Form
  for(int i = 0; i < sz; i++) z[i] = x[i] * y[i];

  ifft(z);  // Inverse FFT
  vector<int> res(sz);
  // Precision problem may occur, round to nearest integer
  for(int i = 0; i < sz; i++) res[i] = z[i].real() + 0.5;

  // remove trailing 0's
  while(res.size() > 1 && res.back() == 0) res.pop_back();
  return res;
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


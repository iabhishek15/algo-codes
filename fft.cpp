
//https://www.spoj.com/problems/POLYMUL/

#include "bits/stdc++.h"
using namespace std;


using cd = complex<double>;
const double PI = acos(-1);

#define int long long


void fft(vector<cd> &a, bool invert) {
  int n = (int)a.size();
  if (n == 1) {
    return ;
  }

  vector<cd> a0(n / 2), a1(n / 2);
  for (int i = 0; 2 * i < n; ++i) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }

  fft(a0, invert);
  fft(a1, invert);
  
  double ang = 2 * PI / n * (invert ? -1 : 1);
  cd w(1), wn(cos(ang), sin(ang));
  for (int i = 0; 2 * i < n; ++i) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    if (invert) {
      a[i] /= 2;
      a[i + n / 2] /= 2;
    }
    w *= wn;
  } 
}


vector<int> multiply(vector<int> const &a, vector<int> const &b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;

  while (n < (int)a.size() + (int)b.size()) {
    n <<= 1;
  }

  fa.resize(n);
  fb.resize(n);

  fft(fa, false);
  fft(fb, false);

  for (int i = 0; i < n; ++i) {
    fa[i] *= fb[i];
  }
  
  fft(fa, true);

  vector<int> result(n);
  for (int i = 0; i < n; ++i) { 
    result[i] = round(fa[i].real());
  }

  return result;
}


void normalise_when_multiplying_two_numbers(vector<int> &result) {
  int carry = 0;
  int n = (int)result.size();
  for (int i = 0; i < n; ++i) {
    result[i] += carry;
    carry = result[i] / 10;
    result[i] %= 10;
  }
}

void solve() {
 
  int n, m; cin >> n;
  n++;
  m = n;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<int> result = multiply(a, b);
  for (int i = 0; i < n + m - 1; ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
}


int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }
 }





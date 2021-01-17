#include "bits/stdc++.h"

using namespace std;

#define all(x)  (x).begin(), (x).end()

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
 
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


#define int long long

int power_mod(int a, int b, int mod) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}

int primitive_root(int p) {
  int phi = p - 1;
  int n = phi;
  vector<int> prime_fact;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      prime_fact.push_back(i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    prime_fact.push_back(n);
  }
  for (int val = 2; val < p; ++val) {
    bool ok = 1;
    for (int j = 0; j < (int)prime_fact.size() && ok; ++j) {
      if (power_mod(val, phi / prime_fact[j], p) == 1) {
        ok = 0;
      }
    }
    if (ok) {
      return val;
    }
  }
  return -1;
}

int power_of_two(int n) {
  int phi = n - 1;
  int l = 0;
  while (phi % 2 == 0) {
    l++;
    phi /= 2;
  } 
  return l;
}

constexpr int mod = 998244353;
const int root = 15311432;
//const int root = primitive_root(mod);
const int root_l = power_mod(root, mod - 2, mod);
const int L = power_of_two(mod);
//const int L = 20;
const int root_pw = 1 << L;

  

int reverse(int num, int lg_n) {
  int res = 0;
  for (int i = 0; i < lg_n; ++i) {
    if ((num >> i) & 1) {
      res |= 1 << (lg_n - 1 - i);
    }
  }
  return res;
}

void fft(vector<int> &a, bool invert) {
  int n = (int)a.size();
  int lg_n = 0;
  while ((1 << lg_n) < n) {
    lg_n++;
  }
  
  for (int i = 0; i < n; ++i) {
    int pos = reverse(i, lg_n);
    if (i < pos) {
      swap(a[i], a[pos]);
    }
  }
  for (int len = 2; len <= n; len <<= 1) { //len = 2, 4, 8, 16 //len <<= 1 left shift
    //root_l = power_mod(root, mod - 2, mod);
    int wlen = invert ? root_l: root; //primitve roots gets reversed in case of inverse
    for (int i = len; i < root_pw; i <<= 1) { //i = len , 2 * len, 4 * len, ... ,(1 << 20)
      wlen =  wlen * wlen % mod;  //this gives the nth bit root //primitive root raised
      //to some power//since (1 << 20) we can store 20 values in an array
    }
    for (int i = 0; i < n; i += len) { //moving over all the n values
      int w = 1;  
      for (int j = 0; j < len / 2; ++j) {
        int u = a[i + j];
        int v = a[i + j + len / 2] * w % mod;
        //a[i + j] = (u + v) % mod;
        a[i + j] = u + v < mod ? u + v : u + v - mod;
        //a[i + j + len / 2] = (u - v + mod) % mod;
        //debug(i, j, i + j, i + j + len / 2, len);
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod; //for i >= n / 2 we subtract
        //debug(a[i + j], a[i + j + len / 2]);
        w = w * wlen % mod; //getting another root I think
      }
    }
    //for (int i = 0; i < n; i += len) {
      // i = 0, 2, 4, 6, 
        // for (int j = 0; j < len / 2; ++j) 
        // j = 0 - 1
      // i = 0, 4, 8, 12
        // j = 0 - 2
      // i = 0, 8, 16, 32
        //j = 0 - 4
  }   

  if (invert) {
    int n_div = power_mod(n, mod - 2, mod);
    for (int &x : a) {
      x = x * n_div % mod;
    }
  }
  //cout << endl;
}



vector<int> multiply(vector<int> &a, vector<int> &b) {
  int n = 1;
  while (n < (int)a.size() + (int)b.size()) {
    n <<= 1;
  }

  a.resize(n, 0);
  b.resize(n, 0);

  fft(a, false);
  fft(b, false);

  for (int i = 0; i < n; ++i) {
    a[i] = a[i] * b[i] % mod;
  }
  
  fft(a, true);
  return a;
}


int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  //debug(root, root_l, root_pw, L);

  //int root = primitive_root_of_mod;
  int n, m; 
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int j = 0; j < m; ++j) cin >> b[j];

  vector<int> res = multiply(a, b);
  for (int i = 0; i < (int)res.size(); ++i) {
    cout << res[i] << " ";
  }
  


}
















#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;

#define rep(pp,nn) for (int ii = pp; ii < nn; ++ii)
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
 
string int_to_string(int x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}
ll lcm(ll a, ll b) {
	return (a * b) / __gcd(a,b);
}
constexpr int mod = 1e9 + 7;

ll power(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}

bool isprime(int n) {
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
                   
int main() {
	int n;
	cin >> n;
	int t = sqrt(n) + 1;
	vector<bool> ch(t + 1);
	vector<int> prime;
	for (int i = 2; i < t; ++i) {
		if (!ch[i]) {
			prime.push_back(i);
			for (int j = i; j <= t; j += i) {
				ch[j] = 1;
			}
		}
	} 
	int p = (int)prime.size();
	int start = t;
	int end = t + t;
	while (start < n) {
		if (end > n) {
			end = n;
		}
		vector<bool> check(t + 1);
		for (int i = 0; i < p; ++i) {
			int s = (start / prime[i]) * prime[i];
			if (start % prime[i] != 0) {
				s += prime[i];
			}
			for (int j = s; j < end; j += prime[i]) {
				check[j - start] = 1;
			}
		}
		for (int i = start; i < end; ++i) {
			if (!check[i - start]) {
				prime.push_back(i);
			}
		}
		start += t;
		end += t;
	}
	//cout << (int)prime.size() << endl;
	for (int i = 0; i < (int)prime.size(); ++i) {
		cout << prime[i] << " ";
	}
}
  
   
   
   
   
   
   
   




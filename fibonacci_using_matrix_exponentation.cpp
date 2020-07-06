#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
 
string int_to_string(int x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}

int mod = 1e9 + 7;
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



ll matlogfib(ll n) {
	ll dp[2][2] = {{1,1},{1,0}};
	static ll a[2] = {1,1};
	while (n) {
		if (n & 1) {
			ll x, y;
			x = ((dp[0][0] * a[0]) % mod + (dp[0][1] * a[1]) % mod) % mod;
			y = ((dp[1][0] * a[0]) % mod + (dp[1][1] * a[1]) % mod) % mod;
			a[0] = x , a[1] = y;
		}
		ll p,q,r,s;
		p = ((dp[0][0] * dp[0][0]) % mod + (dp[0][1] * dp[1][0]) % mod) % mod;
		q = ((dp[0][0] * dp[0][1]) % mod + (dp[0][1] * dp[1][1]) % mod) % mod;
		r = ((dp[1][0] * dp[0][0]) % mod + (dp[1][1] * dp[1][0]) % mod) % mod;
		s = ((dp[1][0] * dp[1][0]) % mod + (dp[1][1] * dp[1][1]) % mod) % mod;
		dp[0][0] = p;
		dp[0][1] = q;
		dp[1][0] = r;
		dp[1][1] = s;
		n /= 2;
	}
	return a[0];
}



int* matfib(int n) {
	int dp[2][2] = {{1,1},{1,0}};
	static int a[2] = {1,1};
	while (n --) {
		int x, y;
		x = dp[0][0] * a[0] + dp[0][1] * a[1];
		y = dp[1][0] * a[0] + dp[1][1] * a[1];
		a[0] = x , a[1] = y;
	}
	return a;
}

 
int main() { 
	ll n;
	cin >> n;
	//cout << matfib(n - 2)[0] << endl; 
	if (n == 1) {
		cout << 1;
		return 0;
	}
	if (n == 0) {
		cout << 0;
		return  0;
	}
	cout << matlogfib(n - 2) << endl;
}





	
